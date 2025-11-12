#include<bits/stdc++.h>
using namespace std;
const int N=503;
const int M=998244353;
int n,m,c[N];
string s;
bool vis[N],ca[N];
long long jie[N],ans=0;
void dfs(int a,int s,int u)
{
	if(s>=m and a<=n+1)
	{
		ans+=jie[n-a+1]%M;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(ca[i]) continue;
		if(c[i]<=u)
		{
			ca[i]=1;
			dfs(a+1,s,u+1);
			ca[i]=0;
			continue;
		}
		if(!vis[a])
		{
			ca[i]=1;
			dfs(a+1,s,u+1);
			ca[i]=0;
			continue;
		} 
		//cout<<true<<endl;
		ca[i]=1;
		dfs(a+1,s+1,u);
		ca[i]=0;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int u=0;
	for(auto i:s)
	{
		u++;
		vis[u]=i-'0';
	}
	bool I1=0;
	for(int i=1;i<=n;i++) if(!vis[i]) I1=1;
	jie[0]=1;jie[1]=1;
	for(int i=2;i<=n;i++) jie[i]=jie[i-1]*i%M;
	if(!I1)
	{
		ans=jie[n];
		cout<<ans<<endl;
		return 0;
	}
	if(m==n)
	{
		cout<<0<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%M<<endl;
	return 0;
}
