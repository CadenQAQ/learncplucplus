#include<thread>
#include<iostream>
#include<array>

void greeting(int idx){
	printf("Test from thread %d\n", idx);
}




int main(void)
{
	std::cout<<"main func begins"<<std::endl;
	const int N = 10;
	std::array<std::thread,N>workers;
	for(int i = 0;i<N;i++)
	{
		workers[i] = std::thread(greeting,i);
	}

	for(auto& worker:workers)
	{
		worker.join();
	}

	return 0;


}

