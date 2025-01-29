
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <chrono>
#include <thread>
#include <functional>

template<typename Iterator, typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
	}
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	unsigned long const length = std::distance(first, last);

	if (!length)
		return init;

	unsigned long const min_threads_per_block = 25;
	unsigned long const max_threads = (length + min_threads_per_block - 1) / min_threads_per_block;

	unsigned long hardware_threads = std::thread::hardware_concurrency();

	unsigned long const num_threads = std::min(hardware_threads == 0 ? 2 : hardware_threads, max_threads);

	unsigned long const block_size = length / num_threads;

	Iterator block_start = first;
	std::vector<std::thread> threads(num_threads - 1);
	std::vector<T> results(num_threads);

	for (unsigned long i = 0; i < (num_threads - 1); i++)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(
			accumulate_block<Iterator, T>(),
			block_start, block_end, std::ref(results[i])
			);
		block_start = block_end;
	}
	accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

	auto result = std::accumulate(results.begin(), results.end(), init);
	return result;
}

int main()
{
	std::vector<int> vec(1000);
	std::generate(vec.begin(), vec.end(), [i{ 0 }]() mutable { return i++; });
	
	// not parallel
	auto start = std::chrono::high_resolution_clock::now();
	unsigned long a = std::accumulate(vec.begin(), vec.end(), 0);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	
	std::cout << a << " " << duration.count() << "s\n";
	
	start = std::chrono::high_resolution_clock::now();
	a = parallel_accumulate(vec.begin(), vec.end(), 0);
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	
	std::cout << a << " " << duration.count() << "s\n";
	return 0;
}