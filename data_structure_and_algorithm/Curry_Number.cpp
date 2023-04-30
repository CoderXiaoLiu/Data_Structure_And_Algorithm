/*
题目大意：寻找1~n里面有多少个因数个数为5的数
解题思路：
经过暴力打表可以发现，质数的4次方都是因数为5的数，因此先素数筛筛出素数来,
然后就可以快速找到位于1~n内的Curry数。
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL maxn = 1e5;
vector<LL>prime;
bool is_prime[maxn+1]; // is_prime[i]为true表示i是素数
void sieve() {
    for(int i = 0; i < maxn; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= maxn; i++) {
        if(is_prime[i]) {
            prime.push_back(i);
            for(int j = 2 * i; j <= maxn; j += i) is_prime[j] = false;
        }
    }
}
bool judge(int x) {
    int sum = 0, res = sqrt(x);
    for(int i = 1; i < res; i++) {
        if(x % i == 0) sum += 2;
    }
    if(x % res == 0 && res * res != x) sum += 2;
    else if(res * res == x) sum++;
    return sum == 5 ? true : false;
}
int main() {
    // for(int i = 1; i <= 100000; i++) 
    //     if(judge(i)) printf("%d\n", i);
    sieve();
    LL n;
    scanf("%lld", &n);
    int ans = 0;
    for(int i = 0; i < prime.size(); i++) {
        if(pow(prime[i], 4) <= n) ans++;
        else break;
    }
    printf("%d", ans);

    return 0;
}