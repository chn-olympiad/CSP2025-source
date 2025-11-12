#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
const int N = 550;
char s[N];
int c[N];
long long dfs(int pai[19],bool vis[19],int sum)
{
	if(sum==n)
	{
		int cc=0;
		for(int i=1;i<=n;i++)
		{
			if(cc>=c[pai[i]])
			{
				cc++;
				continue;
			}
			if(s[i-1]-'0'==0)
			{
				cc++;
				continue;
			}
		}
		if(n-cc>=m)
		{
//			cout<<cc<<"     ";
//			for(int i=1;i<=n;i++)cout<<pai[i]<<" ";
//			cout<<endl;
			return 1;
		}
		return 0;
	}
	long long ans=0;
	bool tvis[19]={};
	int tpai[19]={};
	for(int i=1;i<=n;i++)tvis[i]=vis[i],tpai[i]=pai[i];
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			tvis[i]=1;
			tpai[sum+1]=i;
			ans+=dfs(tpai,tvis,sum+1)%998244353;
			ans=ans%998244353;
			tvis[i]=0;
		}
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	int temp[19]={};
	bool vis[19]={};
cout<<	dfs(temp,vis,0)%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
