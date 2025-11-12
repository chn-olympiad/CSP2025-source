#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int cnt=0;
int k,a[5010];
bool t[5010];
void check(){
	int maxn=0,s=0;
	for(int i=1;i<=k;i++)
		maxn=max(maxn,t[i]*a[i]),
		s+=t[i]*a[i];
	if(s>2*maxn)cnt++,cnt%=mod;
}
void dfs(int x,int cnt){
	if(x>k){if(cnt>=3)check();return;}
	t[x]=0;dfs(x+1,cnt);
	t[x]=1;dfs(x+1,cnt+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	dfs(1,0);
	cout<<cnt;
	return 0;
}
