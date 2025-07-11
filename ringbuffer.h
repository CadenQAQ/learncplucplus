#pragma once
#include<iostream>
#include<atomic>
#include<new>
#include<type_traits>
#include<algorithm>

template<typename T, size_t Capacity>
class RingBuffer
{
public:
    static_assert(Capacity && !(Capacity & (Capacity - 1)), "Capacity must be a power of two");

    RingBuffer(): read_(0), write_(0)


    ~RingBuffer()
    {
        size_t r = read_.load(std::memory_order_relaxed);
        size_t w = write_.load(std::memory_order_relaxed);
    
        while(r!=w)
        {
            reinterpret_cast<T*>(buffer_ + r)->~T();
            r = (r + 1) & (Capacity - 1);
        }
    }

    bool push(const T& value)
    {
        size_t w = write_.load(std::memory_order_relaxed);
        size_t next_w = (w + 1) & (Capacity - 1);

        if (next_w == read_.load(std::memory_order_acquire)) {
            return false; // Buffer is full
        }

        new (reinterpret_cast<T*>(data_ + w)) T(value);
        write_.store(next_w, std::memory_order_release);
        return true;
    }

    size_t Size() const noexcept
    {
        size_t r = read_.load(std::memory_order_relaxed);
        size_t w = write_.load(std::memory_order_relaxed);
        return (w - r) & (Capacity - 1);
    }

private:
    alignas(64) std::atomic<size_t> read_;
    alignas(64) std::atomic<size_t> write_;
    alignas(64) std::aligned_storage_t<sizeof(T), alignof(T)> data_[Capacity];


};

