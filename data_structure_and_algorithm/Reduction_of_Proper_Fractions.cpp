#include<bits/stdc++.h>
using namespace std;
int book[10] = {0};
void judge(int n, int m) {
    int book1[10] = {0}, book2[10] = {0};
    while(n > 0) {
        book1[n % 10] ++;
        n /= 10;
    }
    while(m > 0) {
        book2[m % 10] ++;
        m /= 10;
    }
    for(int i = 0; i < 10; i++) {
        if(book1[i] && book2[i]) book[i] = min(book1[i], book2[i]);
    }
    // for(int i = 0; i< 10; i++) cout << book[i] << " ";
    // cout << endl;
}
int convert(int n) {
    stack<int>s;
    int k;
    int book3[10] = {0};
    for(int i = 0; i < 10; i++) book3[i] = book[i];
    while(n > 0) {
        k = n % 10;
        if(book3[k] > 0) {
            book3[k] --;
        }
        else s.push(k);
        n /= 10; 
    }
    int ans = 0;
    while(!s.empty()) {
        k = s.top();
        s.pop();
        ans = ans * 10 + k;
    }
    return ans;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    judge(n, m);
    int a = convert(n), b = convert(m);
    if(n * b == m * a && a != 0 && b != 0) printf("%d/%d = %d/%d", n, m, a, b);
    else printf("%d/%d != %d/%d", n, m, a, b);
    
    return 0;
}