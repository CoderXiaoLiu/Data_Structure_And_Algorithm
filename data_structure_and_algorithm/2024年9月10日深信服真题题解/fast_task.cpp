/*
有n个任务，序号从1到n,每个任务需要的编辑时间为t分钟。小明和小白需要在对其中k个任务中进行编辑。编辑的过程如下:
n个任务按照顺序排列，他们删除n-k个任务，不改变剩下的k个任务。然后小明选取全部任务的前面一部分任务(可能不选或选择所有任务)，小白选取剩余的，相当于顺序将任务从某个位置分割成两部分，第一部分给小明，第二部分给小白。之后他们分别对各自的任务进行编辑，编辑所需的时间取决于两者中较长的那个。
请帮助小明和小白选择任务和分割方式使编辑尽可能早地完成。
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;

bool cmp(pair <int, int> a, pair <int, int> b) {
    return a.first < b.first;
}

bool cmp2(pair <int, int> a, pair <int, int> b) {
    return a.second < b.second;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int time[n];
        vector <pair<int, int>> tasks;
        for(int i = 0; i < n; i++) {
            scanf("%d", &time[i]);
            tasks.push_back({time[i], i});
        }

        sort(tasks.begin(), tasks.end(), cmp);
        vector <pair<int, int>> do_task;
        for(int i = 0; i < k; i++) do_task.push_back(tasks[i]);
        sort(do_task.begin(), do_task.end(), cmp2);
        vector <int> task;
        for(auto i : do_task) task.push_back(i.first);

        vector <LL> pre(k + 1, 0);
        for(int i = 0; i < k; i ++) pre[i + 1] = pre[i] + task[i];
        LL ans = pre[k];
        // for(int i = 0; i < k + 1; i ++) {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;
        for(int i = 0; i < k + 1; i ++) {
            // cout << ans << " " << pre[i] << " " << pre[k] - pre[i] << endl;
            ans = min(ans, max(pre[i], pre[k] - pre[i]));
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}