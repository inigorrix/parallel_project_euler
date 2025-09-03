#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>
#include <string>

std::mutex mtx;
int total_sum = 0;

void worker(int start, int end){
    int local_sum = 0;
    for (int i=start; i<end; i++){
        if (i%3==0 || i%5==0){
            local_sum += i;
        }
    }
    std::lock_guard<std::mutex> lock(mtx);
    total_sum += local_sum;
}

int main(int argc, char* argv[]){
    int lim = std::stoi(argv[1]);
    std::vector<std::thread> threads;

    int num_threads = 16;

    int chunk = std::ceil(static_cast<float>(lim)/num_threads);

    for (int t = 0; t<num_threads; ++t){
        int start = t * chunk;
        int end = (t+1) * chunk < lim ? (t+1) * chunk : lim;
        threads.emplace_back(worker, start, end);
    }

    for (auto& th : threads) th.join();

    std::cout << total_sum << std::endl;
    return 0;
}

