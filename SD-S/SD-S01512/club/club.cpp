// club.cpp

/*
测试点1-4：直接暴力搜索即可 +20pts
特殊性质A：直接对第一维排序，选最大的n/2个即可 +5pts

首先可以发现由于n/2的限制，每个人的a只有最大的和次大的这两个值是有用的（最小值一定不会被选） 

特殊性质C：（乱搞贪心） 
根据贪心，我们可以先选全局不同的最大的n/2个，这是一定不会超的
然后在剩下的n/2个中，可以把最大值和次大值拆开处理，都打乱放到优先队列中，用标记数组记录使用情况，然后从大到小取出n/2个之后结束就好了 
+10pts？ 

特殊性质B：
相当于我们只要考虑前两维
发现之前贪心的漏洞在于：
例如(10,9)和(4,0)，贪心会选10+0，但正解应该是9+4
换言之，假设有当前已经入选的(最大a,次大b) 和 另外一个因为第一个数被选满而没被入选的(最大c,次大d)，满足b+c>a，那么此时应该替换方案
 

+15pts？ 


目前得分：35pts 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

int n, a[N][5], b[N][5]; // b存最大、次大值的下标 

bool cmp(int x, int y){
	return x > y;
}

ll ans = 0;

void dfs(int now, int *s, ll sum){
	if(now == n + 1){
//		cerr << sum << '\n';
		ans = max(ans, sum);
		return ;
	}
//	dfs(now+1, s1, s2, sum);
	if(s[b[now][0]]+1<=n/2){
		++s[b[now][0]];
		dfs(now+1, s, sum+a[now][b[now][0]]);
		s[b[now][0]] --;
	}
	if(s[b[now][1]]+1<=n/2){
		++s[b[now][1]];
		dfs(now+1, s, sum+a[now][b[now][1]]);
		s[b[now][1]] --;
	}
}

bool cmp2(int x, int y){
	return a[x][b[x][0]] > a[y][b[y][0]]; // 按照最大值排序 
}

struct Node{
	int val, id, pos; // id是第一维，pos是第二维 
	friend bool operator < (Node p1, Node p2){
		return p1.val < p2.val; // 大根堆 
	}
};

void solve()
{	
	cin >> n;
	bool flagA = true; // 特殊性质A：a[i][2]==a[i][3]==0 
	bool flagB = true; // 特殊性质B：a[i][3]==0 
	for(int i = 1; i <= n; i ++){
		b[i][0]=b[i][1]=b[i][2]=0;
		for(int j = 1; j <= 3; j ++){
			cin >> a[i][j];
			if(j >= 2 && a[i][j] != 0) flagA = false;
			if(j == 3 && a[i][j] != 0) flagB = false;
		}
		for(int j = 1; j <= 3; j ++){
			if(a[i][j] > a[i][b[i][0]]){
				b[i][1] = b[i][0]; // 更新次大 
				b[i][0] = j; // 更新最大
			}
			else if(a[i][j] > a[i][b[i][1]]){
				b[i][1] = j; // 更新次大 
			}
		}
//		cerr << b[i][0] << ' ' << b[i][1] << '\n';
	}
	if(n <= 10){
		ans = 0; int s[4] = {0};
		dfs(1, s, 0);
		cout << ans << '\n';
	}
	else if(flagA){
		vector<int> v;
		for(int i = 1; i <= n; i ++){
			v.push_back(a[i][1]);
		}
		sort(v.begin(), v.end(), greater<int>());
		ll res = 0;
		for(int i = 0; i < n/2; i ++){
			res += v[i];
		}
		cout << res << '\n';
	}
	else if(flagB){
		
	}
	else{
		int cnt[5] = {0}; // 记录每个位置被选的次数
		ll res = 0;
		
		// 先找出最大的n/2个 
		vector<int> v; 
		for(int i = 1; i <= n; i ++){
			v.push_back(i);
		}
		sort(v.begin(), v.end(), cmp2);
		vector<int> vis(n+5); // 记录每个i是否有数字被选过 
		for(int i = 0; i < n/2; i ++){
			int t = v[i];
			res += a[t][b[t][0]];
			cnt[b[t][0]] ++;
			vis[t] = 1;
		}
		
		// 处理剩下的
		priority_queue<Node> Q;
		for(int i = n/2; i < n; i ++){
			int t = v[i];
			Q.push({a[t][b[t][0]], t, b[t][0]}); // 最大值
			Q.push({a[t][b[t][1]], t, b[t][1]}); // 次大值
		}
		int ppp = 0; // 记录当前已经有多少
		while(ppp < n/2){
			Node nn = Q.top(); Q.pop();
			int val = nn.val, id = nn.id, pos = nn.pos;
			if(vis[id] || cnt[pos]+1>n/2) continue;
			vis[id] = 1; cnt[pos] ++;
			res += val;
			ppp ++;
		} 
		cout << res << '\n';
	} 
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T --) solve();
	return 0; 
}

/*
1
2
10 9 8
4 0 0

ans=10
*/
