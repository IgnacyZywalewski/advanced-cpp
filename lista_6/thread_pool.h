#pragma once

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <numeric>

class Thread_pool {
	
public:
	Thread_pool(size_t thread_num)
	{
		std::cout << "Liczba rozpoczetych watkow: " << thread_num << "\n";
		for (size_t i = 0; i < thread_num; i++)
		{
			threads.emplace_back([this, i]() 
			{
				//std::cout << "Thread " << i << " started\n";
				while (true)
				{
					std::function<double()> task;
					{
						std::unique_lock<std::mutex> lock(mutex);
						condition.wait(lock, [this]() { return stop_flag || !tasks.empty(); });

						if (stop_flag && tasks.empty())
						{
							return;
						}

						task = std::move(tasks.front());
						tasks.pop();
					}

					double result = task();
					{
						std::lock_guard<std::mutex> lock(results_mutex);
						results.push_back(result);
					}
				}
			});
		}
	}

	~Thread_pool()
	{
		stop();
	}

	void add_task(std::function<double()> task)
	{
		{
			std::lock_guard<std::mutex> lock(mutex);
			tasks.push(std::move(task));
			//std::cout << "Task added to the queue\n";
		}
		condition.notify_one();
	}

	double average()
	{
		std::lock_guard<std::mutex> lock(results_mutex);
		if (results.empty())
		{
			return 0.0;
		}
		return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
	}

	void stop()
	{
		{
			std::lock_guard<std::mutex> lock(mutex);
			stop_flag = true;
		}
		condition.notify_all();

		for (std::thread& thread : threads)
		{
			if (thread.joinable())
			{
				thread.join();
			}
		}
		std::cout << "Thread pool zostal zatrzymany\n";
	}

private:
	std::vector<std::thread> threads;
	std::queue<std::function<double()>> tasks;
	std::vector<double> results;

	std::mutex mutex;
	std::mutex results_mutex;
	std::condition_variable condition;
	std::atomic<bool> stop_flag;
};
