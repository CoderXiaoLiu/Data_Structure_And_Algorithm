# 数位DP

数位动态规划（Digit DP）是一种动态规划的技巧，用于解决与数字相关的问题。它通常用于计算满足一定条件的数字个数或计算某种数字特性的问题。

所谓“数位DP”，是指对数字的位进行的与计数有关的DP。一个数有个位、十位、百位和千位等等，数的每一位就是**数位**。数位DP用来解决与数字操作有关的问题，例如数位之和问题、特定数字问题等。这些问题的特征是给定的区间超级大，不能用暴力的方法逐个检验。数位DP解题的思路是用DP对 *数位* 进行操作，记录已经算过的区间的状态，用在后续计算中，快速进行大范围的筛选。

数位DP的核心思想是将问题分解为更小规模的子问题，并使用动态规划的方式进行求解。在处理数字时，我们会从高位到低位逐个考虑，通过状态转移方程计算出当前位的结果，再根据当前位的结果计算下一位。最终，我们将得到问题的解。

具体而言，数位DP的步骤如下：

1. 定义状态：根据问题的具体情况，定义一个状态表示当前正在处理的位数、已经确定的数字等信息。
2. 确定状态转移方程：根据当前位的情况和前一位的状态，确定状态之间的转移关系。这个转移关系是问题特定的，可能涉及到当前位上数字的限制条件、已经确定的数字等。
3. 处理边界情况：确定起始和结束状态，并初始化边界状态的值。
4. 进行动态规划：按照位数逐个处理，根据状态转移方程计算出当前位的结果，并更新状态。
5. 根据最终状态得出结果：根据问题的要求，从最终状态中提取出所需的信息，得到问题的解。

需要注意的是，数位DP的实现通常需要使用**记忆化搜索**或者**迭代方法**来优化计算过程，以避免重复计算。

总之，数位DP是一种解决与数字相关的问题的动态规划技巧，通过将问题分解为更小规模的子问题，并定义状态转移方程，可以高效地求解满足特定条件的数字个数或计算数字特性的问题。

> 下面就是几道经典的数位DP例题

# 某位博主总结的数位DP模板

在csdn看到了一位大佬总结的模板，感觉十分牛逼，膜拜大佬的一天。

```c++
typedef long long ll;
int a[20];
ll dp[20][state];//不同题目状态不同
ll dfs(int pos,/*state变量*/,bool lead/*前导零*/,bool limit/*数位上界变量*/)//不是每个题都要判断前导零
{
    //递归边界，既然是按位枚举，最低位是0，那么pos==-1说明这个数我枚举完了
    if(pos==-1) return 1;/*这里一般返回1，表示你枚举的这个数是合法的，那么这里就需要你在枚举时必须每一位都要满足题目条件，也就是说当前枚举到pos位，一定要保证前面已经枚举的数位是合法的。不过具体题目不同或者写法不同的话不一定要返回1 */
    //第二个就是记忆化(在此前可能不同题目还能有一些剪枝)
    if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];
    /*常规写法都是在没有限制的条件记忆化，这里与下面记录状态是对应，具体为什么是有条件的记忆化后面会讲*/
    int up=limit?a[pos]:9;//根据limit判断枚举的上界up;这个的例子前面用213讲过了
    ll ans=0;
    //开始计数
    for(int i=0;i<=up;i++)//枚举，然后把不同情况的个数加到ans就可以了
    {
        if() ...
        else if()...
        ans+=dfs(pos-1,/*状态转移*/,lead && i==0,limit && i==a[pos]) //最后两个变量传参都是这样写的
        /*这里还算比较灵活，不过做几个题就觉得这里也是套路了
        大概就是说，我当前数位枚举的数是i，然后根据题目的约束条件分类讨论
        去计算不同情况下的个数，还有要根据state变量来保证i的合法性，比如题目
        要求数位上不能有62连续出现,那么就是state就是要保存前一位pre,然后分类，
        前一位如果是6那么这意味就不能是2，这里一定要保存枚举的这个数是合法*/
    }
    //计算完，记录状态
    if(!limit && !lead) dp[pos][state]=ans;
    /*这里对应上面的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑lead，这里就是lead就完全不用考虑了*/
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)//把数位都分解出来
    {
        a[pos++]=x%10;//个人老是喜欢编号为[0,pos),看不惯的就按自己习惯来，反正注意数位边界就行
        x/=10;
    }
    return dfs(pos-1/*从最高位开始枚举*/,/*一系列状态 */,true,true);//刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为0嘛
}
int main()
{
    ll le,ri;
    while(~scanf("%lld%lld",&le,&ri))
    {
        //初始化dp数组为-1,这里还有更加优美的优化,后面讲
        printf("%lld\n",solve(ri)-solve(le-1));
    }
}
```

> 相信读者还对这个有不少疑问，笔者认为有必要讲一下记忆化为什么是if(!limit)才行，大致就是说有无limit会出现状态冲突，举例：
> 约束：数位上不能出现连续的两个1(11、112、211都是不合法的)
>
> 假设就是[1,210]这个区间的个数
>
> 状态:dp\[pos][pre]:当前枚举到pos位，前面一位枚举的是pre(更加前面的位已经合法了)，的个数(我的pos从0开始)
>
> 先看错误的方法计数，就是不判limit就是直接记忆化
>
> 那么假设我们第一次枚举了百位是0，显然后面的枚举limit=false，也就是数位上0到9的枚举，然后当我十位枚举了1，此时考虑dp\[0][1],就是枚举到个位，前一位是1的个数，显然dp[0][1]=9;(个位只有是1的时候是不满足的)，这个状态记录下来，继续dfs，一直到百位枚举了2，十位枚举了1，显然此时递归到了pos=0,pre=1的层，而dp[0][1]的状态已经有了即dp\[pos][pre]!=-1；此时程序直接return dp\[0][1]了，然而显然是错的，因为此时是有limit的个位只能枚举0，根本没有9个数，这就是状态冲突了。有lead的时候可能出现冲突，这只是两个最基本的不同的题目可能还要加限制，反正宗旨都是让dp状态唯一
>
> 对于这个错误说两点：一是limit为true的数并不多，一个个枚举不会很浪费时间，所以我们记录下! limit的状态解决了不少子问题重叠。第二，有人可能想到把dp状态改一下dp\[pos]\[state][limit]就是分别记录不同limit下的个数，这种方法一般是对的，关于这个具体会讲，下面有题bzoj3209会用到这个。
>
> 数位的部分就是这些，然后就是难点，dp部分，dp大牛的艺术，弱鸡只能看看+...+
>
> 既然从高位往低位枚举，那么状态一般都是与前面已经枚举的数位有关并且通常是根据约束条件当前枚举的这一位能使得状态完整(比如一个状态涉及到连续k位，那么就保存前k-1的状态，当前枚举的第k个是个恰好凑成成一个完整的状态，不过像那种状态是数位的和就直接保存前缀和为状态了)，不过必然有一位最简单的一个状态dp[pos]当前枚举到了pos位。dp部分就要开始讲例题了，不过会介绍几种常用防tle的优化。
> ————————————————
> 版权声明：本文为CSDN博主「wust_wenhao」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
> 原文链接：https://blog.csdn.net/wust_zzwh/article/details/52100392

# HDU-2089 不要62

[hdu-2089 不要62](http://acm.hdu.edu.cn/showproblem.php?pid=2089)

题目大意：一个数字包含 '4' 或者 '62' 的话，就认为这个数字是不吉利的，给定 m 和 n，0 $<$m$\leq$n$<10^6$，统计$[m, n]$范围内吉利数的个数

## 递推实现

基本思路就是在$0$~$10^6$排除不符合条件的数，具体操作是按照“从高位到低位”的顺序进行判断。例如：求 1~ 999 999 内不包含4的数，步骤如下：

1. 在6位数中排除最高位是4的整数，即400 000 ~ 499 999。虽然有10万个数，但只需要判断最高位，一次就全排除了。
2. 最高位不是4的6位数中排除次高位是4的数。例如最高位是1 的数可以一次性排除140 000 ~ 149 999，共一万个。需要**注意的是**，首位**可以是0**，即 000 000 ~ 099 999也算6位数
3. 继续上述步骤直到结束

定义状态$dp[i][j]$，它表示 $i$ 位数中首位是 $j$，符合要求数的个数。例如 $dp[6][1]$表示首位是1的6位数，即100 000 ~ 199 999 中符合要求的数有多少。那么求 $dp[6][1]$只需计算首位数字1后面的5位数就可以了。所以$dp[i][j]$的递推公式如下：
$$
dp[i][j] = \sum_{k=0}^{9}{dp[i-1][k]},\quad(j\ne 4) and (k\ne2 or j \ne 6)
$$

```c++
#include<bits/stdc++.h>
using namespace std;
const int len = 10;
long long dp[10][10] = {0}; // dp[i][j] 表示第一位为 j 的 i 位数的符合条件的数字数量
int digit[12]; // digit[i] 表示存第 i 位数
void init() {
    dp[0][0] = 1;
    for(int i = 1; i <= len; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                // if(j == 4) continue; // 排除数字 4
                // else if(j == 6 && k == 2) continue; // 排除62
                if(j != 4 && (j != 6 || k != 2))
                    dp[i][j] += dp[i - 1][k];
            }
        }
    }
}
int solve(int n) { // 计算[0, n)区间满足条件的数字个数
    memset(digit, 0, sizeof(digit));
    int ans = 0, len = 0;
    while(n > 0) {
        digit[++len] = n % 10;
        n /= 10;
    }
    for(int i = len; i > 0; i--) { // 从 n 的高位到低位
        for(int j = 0; j < digit[i]; j++) {
            if(j != 4 && !(digit[i+1]==6 && j==2))
                ans += dp[i][j];
        }
        if(digit[i] == 4) break; // 第 i 位是4，则第i位后面以4开头后面的数不要了
        if(digit[i + 1] == 6 && digit[i] == 2) break;
    }
    return ans;
}
int main() {
    init();
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) break;
        printf("%d\n", solve(m + 1) - solve(n));
    }

    return 0;
}
```

## 记忆化搜索实现

记忆化搜索其思路就是在递归程序dfs()中搜索所有可能的情况，遇到已经算过的记录在dp[]中的结果就直接调用，不再重复计算。

定义$dp[i]$是$i$位数中符合要求的数字个数。dp[1]表示符合条件的1位数，0是1位数，它的dp[1]=1，1也是1位数，它的dp[1]沿用0算过的dp[1] 即可。dp[2]表示符合条件的2位数的个数，00~09是2位数，计算得到dp[2] = 9；在搜索10~19时，沿用dp[2]即可。后面的同理。

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn = 12;
int dp[maxn][2];
int digit[10] = {0};
int dfs(int len, int pre, int state, bool ismax) { // ismax为数位上界变量  
    if(len == 0) return 1; // 已经递归到 0 位数，返回
    if(!ismax && dp[len][state] != -1) return dp[len][state]; // 记忆化搜索
    int ans = 0, maxx = ismax ? digit[len] : 9;
    for(int i = 0; i <= maxx; i++) {
        if(i == 4) continue;
        if(pre == 6 && i == 2) continue; // 排除62
        ans += dfs(len - 1, i, i == 6, ismax && i == maxx);
    }
    if(!ismax) dp[len][state] = ans;
    return ans;
}

int solve(int n) {
    fill(digit, digit + 10, 0);
    int len = 0;
    while(n > 0) {
        digit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len, -1, 0, true);
}
int main() {
    int m, n, len;
    while(~scanf("%d%d", &m, &n)) {
        if(m == 0 && n == 0) break;
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(n) - solve(m - 1));
    }
    return 0;
}
```

# 233. 数字 1 的个数

给定一个整数 `n`，计算所有小于等于 `n` 的非负整数中数字 `1` 出现的个数。

**示例 1：**

```
输入：n = 13
输出：6
```

**示例 2：**

```
输入：n = 0
输出：0
```

直接套上面的数位dp模板

```cpp
class Solution {
public:
    int dp[10][10], len;
    string s;
    //cnt 表示从当前数字的第 pos 位（从高位到低位的索引，从0开始）到当前位置为止，已经出现了 1 的数量。
    int dfs(int pos, int cnt, bool limit) {
        if(pos == len) return cnt;
        if(!limit && dp[pos][cnt] != -1) return dp[pos][cnt]; 
        int ans = 0, up = limit ? s[pos] - '0' : 9;
        for(int i = 0; i <= up; i++) {
            ans += dfs(pos + 1, cnt + (i == 1), limit && i == up);
        }
        dp[pos][cnt] = ans; // dp[pos][cnt]的值表示当前状态下符合条件的数字的个数。
        return ans;
    }
    int countDigitOne(int n) {
        s = to_string(n);
        len = s.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, true);
    }
};
```

# 902. 最大为 N 的数字组合

[902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/)

给定一个按 非递减顺序 排列的数字数组 digits 。你可以用任意次数 digits[i] 来写的数字。例如，如果 digits = ['1','3','5']，我们可以写数字，如 '13', '551', 和 '1351315'。

返回 可以生成的小于或等于给定整数 n 的正整数的个数 。

![image-20230719120929146](https://typorapic.oss-cn-shenzhen.aliyuncs.com/image-20230719120929146.png)

解题思路：

依然是套上面的模板，但是这道题和求数字1的个数不同的是，这道题需要考虑是否包含前导0 的情况，如果前面没有填入数字，说明这个要填入的数字比限制数字n短，那么这次深搜就不会受到`limit`的约束。

`Limit` 表示当前是否受到了 n 的约束。若`limit`为true，则第 i 位填入的数字至多为 s[i]，否则至多为 9。例如 n=156，如果前面填了 15，那么最后一位至多填 6；如果前面填的不是 15，那么最后一位可以填9。

`lead`为true则表示包含前导0，也就是前面的位数没有填入数字，这样考虑就可以构造出比n位数短的数字。

然后套模板即可。

AC 代码如下：

```cpp
class Solution {
public:
    string s;
    int len, dp[10];
    int dfs(vector<string>& digits, int pos, bool lead, bool limit) { // lead表示是否包含前导0
        if(pos == len) return 1;
        if(!limit && !lead && dp[pos] != -1) return dp[pos]; // dp[pos] 表示数字位数为pos时满足要求的数字个数
        int ans = 0;
        if(lead) ans += dfs(digits, pos + 1, true, false); // 包含前导0，则填入的数字位数比n小，不会受到limit约束
        char up = limit ? s[pos] : '9';
        for(auto digit : digits) {
            if(digit[0] > up) break;
            ans += dfs(digits, pos + 1, false, limit && digit[0] == up);
        }
        if(!limit && !lead) dp[pos] = ans;
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        s = to_string(n);
        len = s.size();
        memset(dp, -1, sizeof(dp));
        return dfs(digits, 0, true, true) - 1; // 减去数字0的情况
    }
};
```

# 788. 旋转数字

[788. 旋转数字](https://leetcode.cn/problems/rotated-digits/)

![image-20230720113905659](https://typorapic.oss-cn-shenzhen.aliyuncs.com/image-20230720113905659.png)

题目大意：

求好数的个数，其中好数不能够包含3、4、7，并且至少包含2、5、6、9中的任意一个，求1 ~ N之间好数的个数

解题思路：

直接套数位 DP 模板

```cpp
class Solution {
public:
    int dp[10][2], len;
    string s;
    bool judge(int x) {
        return x == 2 || x == 5 || x == 6 || x == 9;
    }
    int dfs(int pos, bool good, bool limit) { // dp[pos][good] 表示前pos位已经包含2568和暂未包含2568的好数个数
        if(pos == len) return good; // 包含2、5、6、9才是一个好数
        if(!limit && dp[pos][good] != -1) return dp[pos][good];
        int ans = 0, up = limit ? s[pos] - '0' : 9;
        for(int i = 0; i <= up; i++) {
            if(i == 3 || i == 4 || i == 7) continue;
            ans += dfs(pos + 1, good || judge(i), limit && i == up);
        }
        if(!limit) dp[pos][good] = ans;
        return ans;
    }
    int rotatedDigits(int n) {
        s = to_string(n);
        len = s.length();
        memset(dp, -1, sizeof(dp));
        return dfs(0, false, true);
    }
};
```

