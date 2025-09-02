#include <iostream>
#include <string>

int multiples_3_5(int lim){
    int sum = 0;
    for (int i = 0; i<lim; i+=3){
        sum += i;
    }
    for (int i = 0; i<lim; i+=5){
        if (i%3 != 0){
            sum += i;
        }
    }
    return sum;
}

int main(int argc, char* argv[]){
    std::cout << multiples_3_5(std::stoi(argv[1])) << std::endl;
    return 0;
}
