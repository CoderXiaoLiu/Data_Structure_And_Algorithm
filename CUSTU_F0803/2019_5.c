/*
简单密码
Julius Caesar曾经使用过一种很简单的密码。对于明文中的每个字符，将它用它字母表中后5位对应的字符来代替，这样就得到了密文。比如字符A用F来代替。如下是密文和明文中字符的对应关系。
密文
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
明文
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
你的任务是对给定的密文进行解密得到明文。
你需要注意的是，密文中出现的字母都是大写字母。密文中也包括非字母的字符，对这些字符不用进行解码。
*/
#include<stdio.h>
#include<string.h>
char turn(char a) {
    if(a >= 'A' && a <= 'E') return 'V' + (a - 'A');
    return a - 5;
}
int main() {
    char s[100];
    gets(s);
    int len = strlen(s), i;
    for(i = 0; i < len; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = turn(s[i]);
        }
    }
    printf("%s", s); 
    return 0;
}