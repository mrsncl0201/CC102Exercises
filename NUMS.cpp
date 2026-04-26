#include <iostream>
#include <fstream>
#include<string>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int countPrimes(string filename)
{
    ifstream inFile;
    inFile.open(filename);
    if (!inFile)
    {
        cout<<"cant open "<<filename;
        return -1;
    }

    int count=0; int num;
    while(inFile>>num)
    {
        if (isPrime(num))
            count++;
    }

    inFile.close();
    return count;
}

int main()
{
    int result = countPrimes("NUMS.TXT");
    if (result != -1)
        cout<<"Total number of Primes: " <<result <<endl;
    return 0;
}