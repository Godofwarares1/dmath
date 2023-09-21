#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
#include <list>
#include <thread> 


int sumofmultiplesof3and5(int x)
{
        return((3 * (int((x - 1) / 3) * (int((x - 1) / 3) + 1) / 2)) + (5 * (int((x - 1) / 5) * (int((x - 1) / 5) + 1) / 2)) - (15 * (int((x - 1) / 15) * (int((x - 1) / 15) + 1) / 2)));
}


int fib(int x)
{
        /*prints fibonacci number in the seires*/
        return int (((pow(((1 + pow(5, .5)) / 2), x) - pow(((1 - pow(5, .5)) / 2), (x))) * pow(5, -0.5)));
}


long long int fibSumEvens(long long int x)
{
        /*Find the sum of all even fibanacci numbers up to this number input should be (number in series)/3*/
        return long long int((pow(5, -0.5)) * (1 - pow(((1 + pow(5, 0.5)) / 2), (3 * x)) / (1 - pow(((1 + pow(5, 0.5)) / 2), 3)) - (1 - pow(((1 - pow(5, 0.5)) / 2), (3 * x)) / (1 - pow(((1 - pow(5, 0.5)) / 2), 3)))));
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
        {
                return true;
        }
        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        {
                return false;
        }
        for (int i = 5; i * i <= n; i += 6)
        {
                if (n % i == 0 || n % (i + 2) == 0)
                {
                        return false;
                }
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

std::fstream& GotoLine(std::fstream& file, unsigned int num) {
        file.seekg(std::ios::beg);
        for (int i = 0; i < num - 1; ++i) {
                file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return file;
}

int GPFBetter(long long int n)
{
        std::fstream fout("primes.txt");
        long long int small = pow(n, 0.5);
        long long int GPF = 0;
        long long int prime = 0;
        for (int i = 0; i < small; i++)
        {
                GotoLine(fout, i) >> prime;
                if (prime > GPF)
                {
                        GPF = prime;
                }
        }
        return prime;
}

int greatestprimefactors(long long int n)
{
        std::list<int> primes;
        std::list<int> placeholder;
        for (int i = 2; i <= int(pow(n, 0.5)); i++) 
        {
                primes.push_back(i);
        }
        for (auto i : primes)
        {
                if (n % i == 0) 
                {
                        if (IsPrime(i)) 
                        {
                                placeholder.push_back(i);
                        }
                }
        }
        return (placeholder.back());
}


int ReverseNumber(int num)
{
        int rev_num = 0, remainder = 0;
        if (num % 10 == 0)
        {
                remainder = int(pow(10,3)); 
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
                product *= int(pow(j,int(pow(n,(1.0 / j)))));
        }
        return product;
}


int SquareOfSums(int n)
{
        return int(pow(n * (n + 1) / 2, 2));
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
        return int(n*(log(n) + log(log(n))));
}

int PrimeLowerBound(int n)
{
        return int(n*(log(n) + log(log(n)) - 1));
}


long long int SieveOfAtkin(long long int limit)
{
        const long long int n = 20000000;
        std::list<long long int> primes; 
        static bool sieve[n] = {false}; 
        for (long long int i = 0; i < limit + 1; i++)
        {
                sieve[i] = false;
        }
        sieve[2] = true;
        sieve[3] = true; 

        for (long long int x = 1; x * x <= limit; x++) {
                for (long long int y = 1; y * y <= limit; y++) {

                        // Condition 1
                        long long int n = (4 * x * x) + (y * y);
                        if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                        {
                                sieve[n] ^= true; 
                        }
                                
                        // Condition 2
                        n = (3 * x * x) + (y * y);
                        if (n <= limit && n % 12 == 7)
                        {
                                sieve[n] ^= true; 
                        }

                        // Condition 3
                        n = (3 * x * x) - (y * y);
                        if (x > y && n <= limit && n % 12 == 11)
                        {
                                sieve[n] ^= true;
                        }                               
                }
        }
        for (long long int r = 5; r * r <= limit; r++) {
                if (sieve[r]) {
                        for (long long int i = r * r; i <= limit; i += r * r)
                                sieve[i] = false;
                }
        }
        std::fstream fout;
        fout.open("primes.txt", std::ios::trunc | std::ios::out);
        if (fout.is_open())
        {
                for (long long int a = 1; a <= limit; a++) 
                        if (sieve[a]) 
                        {
                                fout << a << std::endl; 
                        }
                fout.close(); 
                return 0;
        }
        return 1;
        
}

int pythagoreantriplet(int n)
{
        double c = 0.0;
        for (int a = 1; a < n; a++)
        {
                for (int b = 1; b < n; b++)
                {
                        c = pow(pow(a, 2) + pow(b, 2), 0.5);
                        if (a + b + c == n)
                        {
                                return (a * b * c);
                        }
                }
        }
        return 0;
}

auto IntToArray(std::string n) 
{
        long long int num[1000];
        long long int product[1000];
        long long int max = 1;
        int l = sizeof(product) / sizeof(product[0]);
        for (int i = 0; i < l; i++)
        {
                num[i] = (n[i] - 48);
                product[i] = 1;
        }
        for (int j = 0; j < l - 13; j++)
        {
                for (int k = j; k < j + 13; k++)
                {
                        product[j] *= num[k];
                }
                if (product[j] > max)
                {
                        max = product[j];
                }
        }
        return max;
}

void problem1()
{
        std::cout << "The answer to problem 1 is: " << sumofmultiplesof3and5(1000) << std::endl;
}

void problem2()
{
        std::cout << "The answer to problem 2 is: " << problem2_at2(4000000) << std::endl;
}

void problem3()
{
        std::cout << "The answer to problem 3 is: " << greatestprimefactors(600851475143) << std::endl;
}

void problem4()
{
        std::cout << "The answer to problem 4 is: " << LargestPalindrome() << std::endl;
}

void problem5()
{
        std::cout << "The answer to problem 5 is: " << SmallestEvenlyDivisible(20) << std::endl;
}

void problem6()
{
        std::cout << "The answer to problem 6 is: " << SumSquareDifference(100) << std::endl;
}

void problem7()
{
        std::fstream fout("primes.txt");
        long long int problem;
        GotoLine(fout, 10001) >> problem;
        std::cout << "The answer to problem 7 is: " << problem << std::endl;
}

void problem8()
{
        std::cout << "The answer to problem 8 is: " << IntToArray("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450") << std::endl;
}

void problem9()
{
        std::cout << "The answer to problem 9 is: " << pythagoreantriplet(1000) << std::endl;
}

void problem10()
{
        std::cout << "The answer to problem 10 is: " << SieveOfAtkin(2000000) << std::endl;
}



void first10()
{
        problem1();
        problem2();
        problem3();

}

int main()
{
        std::fstream fout("primes.txt");
        auto start = std::chrono::high_resolution_clock::now();
        long long int problem = 0;
        problem7();
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        std::cout << "The answer is " << problem << " This was achieved in " << microseconds << " nanoseconds" << std::endl;
        return 0;
}