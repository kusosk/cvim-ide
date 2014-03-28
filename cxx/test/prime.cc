#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <unordered_map>
#include    <iterator>

using namespace std;
vector<int> prime(int n)
{
    vector<int> res;
    if (n <= 1) return res;
    unordered_map<int, bool> is;
    for (int i = 2; i<=n; ++i) {
        if (i> 2&& !(i%2)) {
            is[i] = false;
            continue;
        }

        unordered_map<int, bool>::iterator
            p = is.find(i);
        if (p == is.end()) {
            is[i] = true;
            int c = i*2;
            while( c<=n) {
                is[c] = false;
                c+=i;
            }
        }
    }
    for (int i = 2; i<=n; i++) 
        if (is[i])
            res.push_back(i);
    return res;
}

vector<int> generate_primes_from_1_to_n(int n)
{
    int size=(int)((n-3)>>1)+1;
    // is_prime[i] represents (2i +_3) is prime or not
    vector<int> primes; // stores the primes from 1 to n
    primes.emplace_back(2);
    vector<bool> is_prime(size, true);
    for (long i=0; i < size; ++i) {
        if (is_prime[i]) {
            int p = (i << 1) + 3;
            primes.emplace_back(p);
            // Sieving from p^2, whose index is 2i^2 + 6i + 3
            for (long j = ((i * i) << 1) + 6 * i + 3; j < size; j += p) { 
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
int main()
{
    vector<int> r1 = generate_primes_from_1_to_n(100);//prime(2);
    copy(r1.begin(), r1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}
