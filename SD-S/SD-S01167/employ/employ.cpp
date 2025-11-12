#include<bits/stdc++.h>
#define int long long
using namespace std;
string str;
const int MOD=998244353;
int n,m,ans;
bool vis[100];
int c[100],C[600];
void dfs(int cnt,int id)
{
	if(n-cnt<m)
	{
		return;
	}	
	if(id==n+1)
	{
		ans=(ans+1)%MOD;
//		cout<<' '<<cnt<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])	continue;
		vis[i]=1;
		if(cnt>=c[i]||str[id]=='0')
		{
//			cout<<"    "<<i<<endl;
			dfs(cnt+1,id+1);
		}
		else
		{
//			cout<<i<<endl;
			dfs(cnt,id+1);
		}
		vis[i]=0;
	}
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	str=' '+str;
//	cout<<str<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=20)
	{
		dfs(0,1);
		cout<<ans<<endl;		
		return 0;
	}
	if(m==1)
	{
		C[0]=C[1]=1;
		for(int i=2;i<=n;i++)
		{
			C[i]=(C[i-1]*i)%MOD;
		}
		cout<<C[n]<<endl;
		return 0;
	}
	if(m==n)
	{
		cout<<0<<endl;
		return 0;
	}
	return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
