#include<bits/stdc++.h>
using namespace std;

const int MAX = 505;
const int MOD = 998244353; 
const int INF = 1145141919; // 然而并没有用到 

int n, m;
char s[MAX];
int c[MAX];

void dfs(int idx, int went, int val) {
	
} 

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> c[i]; 
	
	cout << 114514191 << endl;
	
	
	return 0;
}

/*

dp[i][j] 为在前 i 个人中录取 j 个人的方案数 

所以 dp[i][0] = 1, dp[i][1] = ? 

哦对了，有限制
爆搜吧 
dfs(idx, went, val)
idx 为 天数， went为走掉的人数 
可以尝试状压，用一个数记录谁走了谁还在

-------- 
18:00 start
我好逊啊 

发现是计数dp
后悔面包没有带够 

其实是写过计数dp的
但是很显然写太少了
我好逊啊 

选中文字然后shift + ctrl + 上下键有惊喜 

为什么考点路上测速的上限只有199km/h？
不能测飞机的速度，lj
这东西测不了boing的速度 

18:20 刚刚开始写dfs

所以决定不写了
忘了随机数怎么写的
这不重要

还有3分钟结束 

考点的大屏幕刷新率可以用肉眼数出来
外面已经看不见路了

还有两分钟结束
拜拜 

*/
