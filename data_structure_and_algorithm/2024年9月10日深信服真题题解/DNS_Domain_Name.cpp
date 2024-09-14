/*
验证一个字符串是否是合法的DNS域名。DNS域名的格式要求如下:
1)域名由一系列以点分隔的标签组成。每个标签最长可为63个字节。域名的总长度不能超过 255 字节，包括点。域名至少由2个标签组成。
2)域名标签只能包含字符 a-z、A-Z、0-9 和-(连字符)。不能在标签开头或结尾指定连字符。域名支持大小写，但是不区分大小写。
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if(s.size() > 255 || s[0] == '-' || s[s.size() - 1] == '-') {
        puts("false");
        return 0;
    } 
    int cnt = 1;
    bool label = false;
    for(int i = 1; i < s.size(); i++) {
        cnt++;
        if(s[i] == '.') {
            label = true;
            if(cnt - 1 > 63) {
                puts("false");
                return 0;
            }
            if(s[i - 1] == '-' || s[i + 1] == '-') {
                puts("false");
                return 0;
            }
            cnt = 0;
        }
        else if(!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '-' && s[i] != '.') {
            puts("false");
            return 0;
        }
    }
    if(!label) puts("false");
    else puts("true");

    return 0;
}