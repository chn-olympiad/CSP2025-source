#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1000,mod = 998244353;
int n,m,a[maxn+100],c[maxn+100],cnt = 0;
char s[maxn+100];
bool vis[maxn+100];

bool check(){
	int wl = 0,yl = 0;
	for(int i = 1;i <= n;i++){
		if(wl >= c[a[i]]){
			wl++;
			continue;
		}
		if(wl > n-m) return 0;
		if(s[i] == '1') yl++;
		else wl++;
	}
	if(yl >= m){
		return 1;
	}
	return 0;
}

void dfs(int dep){
	if(dep == n+1){
		if(check() == 1) cnt++;
		cnt %= mod;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == 0){
			a[dep] = i;
			vis[i] = 1;
			dfs(dep+1);
			vis[i] = 0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		if(s[i] == '0') flag = 0;
	}
	for(int i = 1;i <= n;i++) cin >> c[i];
	if(n == m && n > 18){
		for(int i = 1;i <= n;i++){
			if(s[i] == '0' || c[i] == 0){
				cout << 0 << '\n';
				return 0;
			}
		}
		int res = 1;
		for(int i = n;i >= 1;i--){
			res = res * i % mod;
		}
		cout << res << '\n';
		return 0;
	}
	if(n > 18 && flag == 1){
		int res = 1,cnt = n;
		for(int i = 1;i <= n;i++){
			if(c[i] == 0) cnt--;
		}
		if(cnt < m){
			cout << m << '\n';
			return 0;
		}
		for(int i = 1;i <= n;i++){
			res = res * i % mod;
		}
		cout << res << '\n';
		return 0;
	}
	if(n <= 18) dfs(1);
	else{
		cnt = 1;
		for(int i = 1;i <= n;i++){
			cnt = cnt * i % mod;
		}
	}
	cout << cnt << '\n';
	return 0;
}

/*
3 2
101
1 1 2

3 1
111
0 1 2
*/

/*
感觉没有什么可以拿的分了啊
我还是太菜了
100+[50,64]+10+[12,16] = [172,190]
但愿不要挂分！
感觉今年题目比去年难啊
不过我已经释怀了
至少打的比去年好
本来就是whk选手没什么好纠结的
T2居然是图论
一眼最小生成树，不会建模qwq
估计又是全机房垫底 
人生最后一次CSP-S了，大概率2= 
6钩可能有吧、、、
自己尽力了，感觉这几道题目没有我强项 
NOIP继续加油吧！
Luogu uid:713343
宵宫梦男 & 奶味蓝
唯一老婆：宵宫
主担：Miyeon（团粉偏面） 
好感霞之丘，由比滨结衣，NMIXX，izna
关注 Luogu 713343 谢谢喵！
哦对了Miyeon solo 2在大家看到这个代码之前发布了，多多关注谢谢喵！
米哈游加强宵宫！ 
*/
