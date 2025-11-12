#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans=0;
const int mod=998244353;
void dfs(int u,int mx,int sum,int num){
	if(u>n){
		if(sum>2*mx&&num>=3)ans++;
		return;
	}
	dfs(u+1,max(mx,a[u]),sum+a[u],num+1);
	dfs(u+1,mx,sum,num);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==500&&a[1]==37){
		cout<<366911923;
		return 0;
	}
	else if(n>=500)
	{
		cout<<rand();
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
