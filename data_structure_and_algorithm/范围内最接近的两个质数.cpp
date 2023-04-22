/*
素数筛
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
bool prime[1000020] = {false}; // 标记i是不是素数
int primes[1000020] = {0}, cnt;// 存储素数
void Set() {
    cnt=1;
    memset(prime,1,sizeof(prime));//初始化认为所有数都为素数
    prime[0]=prime[1]=0;//0和1不是素数
    for(long long i=2;i<=maxn;i++)
    {
        if(prime[i])
            primes[cnt++]=i;//保存素数i
        for(long long j=1;j<cnt && primes[j]*i<maxn;j++)
        {
            prime[primes[j]*i]=0;//筛掉小于等于i的素数和i的积构成的合数
        }
    }
}
vector<int> closestPrimes(int left, int right) {
    Set();
    vector <int> ans;
    int low = left, high = right;
    bool flag = false;
    for(int i = 0; i < cnt - 1; i++) {
        if(primes[i]>= left && primes[i] <= right) {
            if(primes[i+1] >= left && primes[i+1] <= right) {
                if(primes[i+1] - primes[i] < high - low) {
                    low = primes[i], high = primes[i+1];
                    flag = true;
                }
            }
        }
    }
    if(!flag && (!prime[low] || !prime[high])) ans.push_back(-1), ans.push_back(-1);
    else ans.push_back(low), ans.push_back(high);
    return ans;
}
int main() {
    int left, right;
    scanf("%d%d", &left, &right);
    vector<int>v;
    v = closestPrimes(left, right);
    cout << v[0] << " " << v[1];

    return 0;
}
/*
84084 407043
710119 710189
*/