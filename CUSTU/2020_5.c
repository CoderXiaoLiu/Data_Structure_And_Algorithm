/*
编写一个程序，输入一个长度不超过100的字符串，并删除字符串中重复的字符串
样例输入：abacaeedabcdcd
样例输出：abcd
*/
#include<stdio.h>
#include<string.h>
int main() {
    char s[100];
    scanf("%s", s);
    int visited[100] = {0}, i, j, len = strlen(s);
    for(i = 0; i < len; i++) {
        for(j = i + 1; j < len; j++) {
            if(s[i] == s[j] && visited[j] == 0) { // 如果重复则标记为1
                visited[j] = 1;
            }
        }
    }
    for(i = 0; i < len; i++) {
        if(visited[i] == 0) printf("%c", s[i]);
    }
    return 0;
}