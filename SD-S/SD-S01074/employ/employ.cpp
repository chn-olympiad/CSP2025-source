#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
/*====================*/
const int mod=998244353;
const int N=510;
/*====================*/
int n,m;
string s;
int c[N];
//int ans[N];
ll fw1[N];
ll ans=0;
bool vis[N];
/*====================*/
ll fw(int k)
{
	if(k<=0)return 0;
	if(fw1[k])return fw1[k];
	fw1[k]=1ll*fw(k-1)*k%mod;
	return fw1[k];
}
/*====================*/
void dfs(int step,int sum,int gu)
{
	if(sum+n-step+1<m)return;
	if(sum>=m)
	{
//		cout<<n-step+1<<endl;
		ans=(ans+fw(n-step+2))%mod;
		return;
	}
	if(step==n+1)
	{
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		if(gu<c[i]&&s[step]-'0'==1)dfs(step+1,sum+1,gu);
		else dfs(step+1,sum,gu+1);
		vis[i]=0;
	}
}
//void dfs1(int step,int sum,int gu)
//{
//	
//}
/*====================*/
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fw1[1]=1;
	cin>>n>>m;
	cin>>s;
	s="1"+s;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(s[i]=='1')flag++;
	}
//	if(flag==n)
//	{
//		int tot=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(c[i])tot++;
//		}
//		if(tot>=m)
//		{
//			cout<<fw(n)<<endl;
//			return 0;
//		}
//		else
//		{
//			cout<<0<<endl;
//			return 0;
//		}
//	}
	if(flag<m)
	{
		cout<<0<<endl;
		return 0;
	}
//	if(flag<=18)
//	{
//		int tot2=0;
//		ans[0]=1;
//		for(int i=1;i<=n;i++)
//		{
//			if(s[i]=='1')ans[++tot2]=i;
//		}
//		dfs1(1,0,0);
//	}
	dfs(1,0,0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
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
