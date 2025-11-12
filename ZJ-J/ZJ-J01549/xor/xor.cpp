#include<bits/stdc++.h>
using namespace std;
const int inf=5*1e5+1;
long long mx=-1,n[inf],m,k;
bool flag[inf];
void dfs(long long v,long long ans,long long dis)
{
	if(dis>m)
	{
		mx=max(ans,mx);
		return ;
	}
	if(v==k)
	{	
		dfs(n[dis],ans+1,dis+1);
	}
	else
	{
		dfs((v^n[dis]),ans,dis+1);
		dfs(n[dis],ans,dis+1);
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>n[i];
	}
	dfs(n[1],0,1);
	cout<<mx;
	return 0;
}

