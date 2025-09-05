#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <string>

void worker(int start, int end, int& local_sum){
    for (int i=start; i<end; i++){
        if (i%3==0 || i%5==0){
            local_sum += i;
        }
    }
}

int main(int argc, char* argv[]){
    int lim = std::stoi(argv[1]);
    std::vector<std::thread> threads;

    int num_threads = 16;
    std::vector<int> local_sums(num_threads);

    int chunk = std::ceil(static_cast<float>(lim)/num_threads);

    for (int t = 0; t<num_threads; ++t){
        int start = t * chunk;
        int end = (t+1) * chunk < lim ? (t+1) * chunk : lim;
        threads.emplace_back(worker, start, end, std::ref(local_sums[t]));
    }

    for (auto& th : threads) th.join();

    int total_sum = 0;
    for (auto& s : local_sums) total_sum += s;

    std::cout << total_sum << std::endl;
    return 0;
}

