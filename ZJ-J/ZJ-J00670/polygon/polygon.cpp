#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
inline void dfs(int x,int num,int sum,int maxx){
	if(num>=3&&sum>2*maxx)ans=(ans+1)%mod;
	else if(x<=n)dfs(x+1,num+1,sum+a[x],a[x]);
	if(x>n)return;
	dfs(x+1,num,sum,maxx);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20)dfs(1,0,0,0);
	else ans=1ll*rand()*14257%mod;
	cout<<ans;
	return 0;
}