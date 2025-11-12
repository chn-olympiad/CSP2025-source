#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10,mod=998244353;
int n,a[N],ans;
void dfs(int i,int num,int pose,int ma,int sum)
{
	if(num==pose)
	{
		if(sum>ma*2) ans=(ans+1)%mod;
		if(pose<n) dfs(i,num,pose+1,ma,sum);
		return ;
	}
	if(pose<=n&&i<=n)
	{
		dfs(i+1,num,pose,ma,sum);
		if(a[i]!=0)dfs(i+1,num+1,pose,max(ma,a[i]),sum+a[i]);
	}
	
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,3,0,0);
	cout<<ans;


	return 0;
}

