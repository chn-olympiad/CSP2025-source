#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int c[N],n,m,ans,a[N],vis[N],p,d;
string s;
void dfs(int x){
	if(x==n){
		p=0;d=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'||c[a[i]]<=p)p++;
			else d++;
		}
		if(d>=m)ans++;
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int j=0; j<n; j++)cin>>c[j];
	dfs(0);
	cout<<ans<<endl;
}
//一回合…一次？
//我只会暴力
//首先n<500,大胆猜测n^3
//于是想到dp
//考虑dp[a][b][c]表示到第a天录取了b个人剩下最小耐心的人为c的方案数
//此时已是n^4,胜利就在前方
//然而作为一个AFOer，我们并没有想出解法
//suo yi 10 pts
