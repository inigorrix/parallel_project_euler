#include <iostream>
#include <string>

int fibo_sum(int lim){
    int sum=0;
    int a{1},b{2},c{3};
    while(b < lim){
        sum += b;
        a = b+c;
        b = a+c;
        c = a+b;
    }
    return sum;
}

int main(int argc, char* argv[]){
    std::cout << fibo_sum(std::stoi(argv[1])) << std::endl;
    return 0;
}
