#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x;i<=y;i++)
#define mod 998244353
int n;
int a[5020];
int ans;
void dfs(int now,int sum,int choose,int maxn,int k){
	if(choose>=3 && sum>maxn*2 && k){
		ans++;
		ans%=mod;
	}
	if(now==n+1){
		return;
	}
	dfs(now+1,sum+a[now],choose+1,max(maxn,a[now]),1);
	dfs(now+1,sum,choose,maxn,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	f(i,1,n) cin>>a[i];
	dfs(1,0,0,0,1);
	cout<<ans;
	return 0;
}

