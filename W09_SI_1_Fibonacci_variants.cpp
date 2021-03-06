
//zadanie robione grupowo

#include <iostream>

int additions = 0;
int* memory;

//dla n=0: Fn = 0
//dla n=1: Fn = 1
//dla n> 1: Fn = Fn-1 + Fn-2 

// Level 0: iterative
int iterative(int n)
{
    int nMin2 = 0, nMin1 = 1, nEl = 0;

    if (n <= 1) 
        return n;
    else {
        for (int i = 2; i <= n; i++)
        {
            additions++;
            nEl = nMin2 + nMin1;
            nMin2 = nMin1;
            nMin1 = nEl;
        }
    }
    return nEl;
}

// Level 1: naive recursive
int recursiveNaive(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        additions++;
        return recursiveNaive(n - 1) + recursiveNaive(n - 2);
    }
}

// Level 2: recursive with memorization
int recursiveMemo(int n) {

    if (n <= 1) {
        return n;
    }
    else if (memory[n - 1] != 0)
        return memory[n - 1];
    else {
        additions++;
        return memory[n - 1] = recursiveMemo(n - 1) + recursiveMemo(n - 2);
    }
}
// Level 3: tail recursive
int recursiveTail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    additions++;
    std::cout << "n= " << n << ", a= " << a << ", b= " << b << std::endl;
    return recursiveTail(n - 1, b, a + b);
}

int main() {
    clock_t start, stop;
    double time; 
    int choice; //user can choose for which value he wants to run the program 
    
    std::cout << "For which value you want to do the calculations?" << std::endl;
    std::cin >> choice;
   
    start = clock();
    std::cout << "Level 0: Iterative " << iterative(choice) << std::endl;
    stop = clock();
    std::cout << "Number of additions: " << additions;
    time = (double)(stop - start) / (CLOCKS_PER_SEC/1000);
    std::cout << "   Time: " << time << "ms" << std::endl;

    start = clock();
    std::cout << "\nLevel 1: Naive recursive " << recursiveNaive(choice) << std::endl;
    stop = clock();
    std::cout << "Number of additions: " << additions << std::endl;
    time = (double)(stop - start) / (CLOCKS_PER_SEC / 1000);
    std::cout << "   Time: " << time << "ms" << std::endl;

    int n = 10;
    memory = new int[n];
    for (int i = 0; i < n; i++)
    {
        memory[i] = 0;
    }
    start = clock();
    std::cout << "\nLevel 2: Recursive with memorization " << recursiveMemo(choice) << std::endl;
    stop = clock();
    std::cout << "Number of additions: " << additions << std::endl;
    time = (double)(stop - start) /(CLOCKS_PER_SEC/1000) ;
    std::cout << "   Time: " << time << "ms" << std::endl;

    delete[] memory;

    start = clock();
    std::cout << "\nLevel 3: Tail recursive " << recursiveTail(choice) << std::endl;
    stop = clock();
    std::cout << "Number of additions: " << additions << std::endl;
    time = (double)(stop - start) / (CLOCKS_PER_SEC /1000);
    std::cout << "   Time: " << time << "ms" << std::endl;

    return 0;
} 
