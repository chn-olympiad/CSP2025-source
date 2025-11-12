#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5,mod=998244353;
int flag[N],val[N],n,ans;
bool check(){
	int mx=-1,res=0,ts=0;
	for(int i=1;i<=n;i++)
		if(flag[i])
			ts++,res+=val[i],mx=max(mx,val[i]);
	return ((res>mx*2)&&(ts>=3));
}
void dfs(int now){
	if(now==n+1){
		if(check())ans++,ans%=mod;
		return ;
	}
	flag[now]=1;
	dfs(now+1);
	flag[now]=0;
	dfs(now+1);
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	if(n>30){
		cout<<0<<'\n';
		return 0;
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/