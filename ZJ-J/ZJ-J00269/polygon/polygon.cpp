#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0;
bool check(int sum,int mx){
	
	if(sum>2*mx) return 1;
	return 0;
}

void dfs(int s,int sum,int mx,int t){
	int u=a[s];
	if(s==n+1){
		if(t<3) return;
		if(check(sum,mx)) ans++;
		return;
	}
	dfs(s+1,sum+u,u,t+1);
	dfs(s+1,sum,u,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans%998244353;
	return 0;
}
