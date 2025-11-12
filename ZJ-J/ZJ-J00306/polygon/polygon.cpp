#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,a[5005],ans;
void dfs(int d,ll sum,ll mx,int i,bool f)
{
	if(d>=3&&sum>mx*2&&f)
		ans++,ans%=mod;
	if(i>n)
		return ;
	dfs(d+1,sum+a[i],max(a[i],mx),i+1,true);
	dfs(d,sum,mx,i+1,false);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			f=false;
	}
	if(f)
	{
		int k=0;
		ll dt[5001]={0};
		for(int i=1;i<=n-2;i++)
			k+=i,dt[i]=dt[i-1]*2+k,dt[i]%=mod;
		cout<<dt[n-2]<<endl;
		return 0;
	}	
	ans=0;
	dfs(0,0,0,1,true);
	cout<<ans;
}