#include <cstdio>
#include <iostream>
#include <chrono>
#include <cmath>
#include <list>


int sumofmultiplesof3and5(int x)
{
        return((3 * (int((x - 1) / 3) * (int((x - 1) / 3) + 1) / 2)) + (5 * (int((x - 1) / 5) * (int((x - 1) / 5) + 1) / 2)) - (15 * (int((x - 1) / 15) * (int((x - 1) / 15) + 1) / 2)));
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


/* removes multiples of index n in a list*/
auto removeMultiples(std::list<int> primes, int n) {
        std::list<int> placeholder;
        auto x = std::next(primes.begin(), n);
        for (auto prime : primes)
        {

                if ((prime % *x != 0) || (prime == *x))
                {
                        placeholder.push_back(prime);
                }

        }
        return placeholder;
}

/*basic prime test found on wiki*/
bool IsPrime(int n)
{
        if (n == 2 || n == 3)
                return true;

        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
                return false;

        for (int i = 5; i * i <= n; i += 6)
        {
                if (n % i == 0 || n % (i + 2) == 0)
                        return false;
        }
        return true;
}

/*Fairly good at getting the first few hundred primes but way too slow to be of any use*/
std::list<int> SieveOfEratosthenes(int n)
{
        std::list<int> primes;
        std::list<int> placeholder;
        for (int i = 2; i <= n; i++) {
                primes.push_back(i);
        }
        for (int j = 0; j <= 3; j++) {
                primes = removeMultiples(primes, j);
        }
        return (primes);
}


int greatestprimefactors(int n)
{
        std::list<int> primes;
        std::list<int> placeholder;
        for (int i = 2; i <= int(pow(n, 0.5)); i++) {
                primes.push_back(i);
        }
        for (auto i : primes)
        {
                if (n % i == 0) {
                        if (IsPrime(i)) {
                                placeholder.push_back(i);
                        }
                }
        }
        return (placeholder.back());
}

 
auto quadraticsieve()
{

        return 0;
}

int ReverseNumber(int num)
{
        int rev_num = 0, remainder = 0;
        if (num % 10 == 0)
        {
                remainder = pow(10,3); 
        }
        while (num != 0) 
        {
                rev_num = rev_num * 10 + (num % 10);
                num /= 10;
        }
        return(rev_num + remainder);
}


int CreatePalindrome(int num) {
        int rev_num = ReverseNumber(num);
        num *= 1000;
        if (rev_num > 1000)
        {
                num = rev_num + num - 1000;
        }
        else
        {
                num += rev_num;
        }
        return(num);
}

int LargestPalindrome()
{
        int rev_num = 0;
        std::list<int> solid_nums;  
        std::list<int> palindrome_num; 
        for (int i = 900; i < 1000; i++)
        {
                solid_nums.push_back(i);
        }
        for (auto n : solid_nums)
        {
                for (auto j : solid_nums) {
                        if (n * j == ReverseNumber(n * j))
                        {
                            palindrome_num.push_back(n*j);
                        }   
                }
        }
        palindrome_num.sort();
        return (palindrome_num.back());
}

int SmallestEvenlyDivisible(int n)
{
        std::list<int> primes = SieveOfEratosthenes(n);
        int product = 1;
        for (auto j : primes)
        {
                product *= pow(j,int(pow(n,(1.0 / j))));
        }
        return product;
}


int SquareOfSums(int n)
{
        return pow(n * (n + 1) / 2, 2);
}

int SumOfSquares(int n)
{
        return n*(n+1)*(2*n+1)/6;
}

int SumSquareDifference(int n)
{
        return SquareOfSums(n) - SumOfSquares(n);
}

int PrimeUpperBound(int n)
{
        return n*(log(n) + log(log(n)));
}

int PrimeLowerBound(int n)
{
        return n*(log(n) + log(log(n)) - 1);
}


void SieveOfAtkin(int limit)
{
        std::list<int> primes; 
        bool* sieve = new bool(limit);
        for (int i = 0; i <= limit; i++)
                sieve[i] = false;

        sieve[2] = true;
        sieve[3] = true;

        for (int x = 1; x * x <= limit; x++) {
                for (int y = 1; y * y <= limit; y++) {

                        // Condition 1
                        int n = (4 * x * x) + (y * y);
                        if (n <= limit
                                && (n % 12 == 1 || n % 12 == 5))
                                sieve[n] ^= true;

                        // Condition 2
                        n = (3 * x * x) + (y * y);
                        if (n <= limit && n % 12 == 7)
                                sieve[n] ^= true;

                        // Condition 3
                        n = (3 * x * x) - (y * y);
                        if (x > y && n <= limit
                                && n % 12 == 11)
                                sieve[n] ^= true;
                }
        }
        for (int r = 5; r * r <= limit; r++) {
                if (sieve[r]) {
                        for (int i = r * r; i <= limit; i += r * r)
                                sieve[i] = false;
                }
        }
        for (int a = 1; a <= limit; a++)
                if (sieve[a])
                {
                        primes.push_back(a);
                        std::cout << a << " ";
                }
}


int main()
{
        auto start = std::chrono::high_resolution_clock::now();
        int problem = 0;
        SieveOfAtkin(114319);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        std::cout << "The answer is " << problem << " This was achieved in " << microseconds << " nanoseconds" << std::endl;
        return 0;
}