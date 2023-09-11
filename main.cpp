#include <cstdio>
#include <iostream>
#include <chrono>
#include <cmath>
#include <list>

int problem1_at1(int x)
{
        long long sum1 = 0;
        for (long long i = 0; i < x; i++)
        {
                if (i % 3 == 0 || i % 5 == 0)
                {
                        sum1 += i;
                }
        }
        return sum1;
}

int problem1_at2(int x)
{
        int i_3;
        int i_5;
        int sum1 = 0;
        for (int i = 0; i < int(x / 3); i++)
        {
                i_3 = i * 3;
                i_5 = i * 5;
                if ((i_5 > x) || (i_5 % 3 == 0))
                {
                        sum1 += i_3;
                }
                else
                {
                        sum1 += (i_3 + i_5);
                }
        }
        return (sum1 - 1);
}

int problem1_at3(int x)
{
        int sum1 = 0;
        for (int i = 0; i <= int(x / 3); i++)
        {
                sum1 += i * 8;
        }
        for (int n = int(x / 5); n <= int(x / 3); n++)
        {
                sum1 -= 5 * n;
        }
        for (int j = 0; j <= int(x / 15); j++)
        {
                sum1 -= 15 * j;
        }
        return sum1;
}

int problem1_at4(int x)
{
        int sum1 = 0;
        for (int i = 0; i <= int(x / 3); i++)
        {
                sum1 += i * 8;
                if (i >= int(x / 5))
                {
                        sum1 -= 5 * i;
                }
                if (i <= int(x / 15))
                {
                        sum1 -= 15 * i;
                }
        }
        return sum1;
}

int problem1_at5(int x)
{
        return((3 * (int((x - 1) / 3) * (int((x - 1) / 3) + 1) / 2)) + (5 * (int((x - 1) / 5) * (int((x - 1) / 5) + 1) / 2)) - (15 * (int((x - 1) / 15) * (int((x - 1) / 15) + 1) / 2)));
}

int problem2_at1(long long x)
{
        int fib1 = 1;
        int fib2 = 1;
        int fib3;
        int sum_even = 0;
        while (fib1 < x)
        {
                fib3 = fib2;
                fib2 = (fib1 + fib2);
                fib1 = fib3;
                if (fib2 % 2 == 0)
                {
                        sum_even += fib2;
                }
        }
        return sum_even;
}

int fib(int x)
{
        /*prints fibonacci number in the seires*/
        return(((pow(((1 + pow(5, .5)) / 2), x) - pow(((1 - pow(5, .5)) / 2), (x))) * pow(5, -0.5)));
}


int fibSumEvens(int x)
{
        /*Find the sum of all even fibanacci numbers up to this number input should be (number in series)/3*/
        return(pow(5, -0.5)) * (1 - pow(((1 + pow(5, 0.5)) / 2), (3 * x)) / (1 - pow(((1 + pow(5, 0.5)) / 2), 3)) - (1 - pow(((1 - pow(5, 0.5)) / 2), (3 * x)) / (1 - pow(((1 - pow(5, 0.5)) / 2), 3))));
}

int problem2_at2(int maxfib)
{
        /* find the sum of all even fobonacci numbers under maxfib*/
        return(fibSumEvens(int((log2(maxfib) / log2((1 + pow(5, 0.5)) / 2) + ((1 + pow(5, 0.5)) / 2)) / 3) + 1));
}


/*Code doesn't work need to look at it later*/
auto removeMultiples(std::list<int> primes, int n) {
        std::list<int> placeholder;
        auto x = std::next(primes.begin(), n);
        for (auto prime : primes)
        {

                if (prime % *x != 0 && prime > *x)
                {
                        placeholder.push_back(prime);
                }
                else if (prime % *x == 0 && prime > *x)
                {

                }
                else
                {
                        placeholder.push_back(prime);
                }
        }
        return placeholder;
}

auto sieveoferatosthenes()
{
        std::list<int> primes;
        std::list<int> placeholder;
        for (int i = 2; i <= 100; i++) {
                primes.push_back(i);
        }
        int j = 0;
        while (j <= 50) {
                primes = removeMultiples(primes, j);
                j++;
        }
        for (auto i : primes)
        {
                std::cout << i << ' ';
        }
        std::cout << primes.size() << " ";
        return 0;
}

/*end non functional code*/
 


int main()
{
        auto start = std::chrono::high_resolution_clock::now();
        int problem;
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        return 0;
}