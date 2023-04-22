/*
解题思路：
双栈，一个栈用于存放字符串，一个栈用于存放数字。
首先定义两个栈 st_string 和 st_num，用于存放字符和数字。
定义一个字符串 temp 和一个整型变量 num，分别用于记录当前扫描到的未被编码的字符串和数字。
通过 for 循环遍历输入字符串 s 中的每个字符，依次进行操作：
如果当前字符为 '['，则将 temp 和 num 分别压入对应的栈中，并将它们清空。
如果当前字符为 ']'，则取出 st_string 和 st_num 栈顶的元素 topn 和 tops，将temp追加topn次到tops末尾，然后将tops的值赋值给temp。
如果当前字符为数字，则一直读取数字，直到不再是数字，将得到的数字赋值给 num。
如果当前字符为字母，则一直读取字母，直到不再是字母，将得到的字符串拼接到 temp 的末尾。
最终返回解码后的字符串 temp。
*/
#include<bits/stdc++.h>
using namespace std;
string decodeString(string s) {
    stack<string>st_string;
    stack<int>st_num;
    string temp = "";
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '[') {
            st_string.push(temp);
            st_num.push(num);
            num = 0;
            temp = "";
        }
        if(s[i] == ']') { // 这一段话没看懂的话建议拿 3[a2[c]] 这个样例到草稿纸上模拟一下双栈的运行过程
            int topn = st_num.top();
            st_num.pop();
            string tops = st_string.top();
            st_string.pop();
            for(int j = 0; j < topn; j++) tops = tops + temp;
            temp = tops;
        }
        if(isdigit(s[i])) {
            while(isdigit(s[i])) num = num * 10 + (s[i++] - '0');
            i--; // 回退一位回去，不然for循环的i++会导致直接移动了两次
        }
        if(isalpha(s[i])) {
            while(isalpha(s[i])) temp = temp + s[i++];
            i--;
        }
    }
    return temp;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin >> s;
        cout << decodeString(s) << "\n";
    }
    return 0;
}
/*
4
3[a]2[bc]
3[a2[c]]
2[abc]3[cd]ef
abc3[cd]xyz
*/