#include<bits/stdc++.h>
using namespace std;
int n,k,b[1005][1005],cnt,maxn;
int ke1[100005],ke2[100005];
bool keng[1005];
void dfs(int ci,int now)
{
	if(now==cnt)
	{
		maxn=max(maxn,ci);
		return;
	}
	for(int i=now+1;i<=cnt;i++)
	{
		bool p=0;
		for(int j=ke1[i];j<=ke2[i];j++)
		{
			if(keng[j])
			{
				p=1;
			}
		}
		if(!p)
		{
			for(int j=ke1[i];j<=ke2[i];j++)
			{
				keng[j]=1;
			}
			dfs(ci+1,i);
			for(int j=ke1[i];j<=ke2[i];j++)
			{
				keng[j]=0;
			}	
			break;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i][i];
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b[i][j]=b[i][j-1]^b[j][j];
			if(b[i][j]==k)
			{
				ke1[++cnt]=i,ke2[cnt]=j;
			}
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=ke1[i];j<=ke2[i];j++)
		{
			keng[j]=1;
		}
		dfs(1,i);
		for(int j=ke1[i];j<=ke2[i];j++)
		{
			keng[j]=0;
		}
	}
	cout<<maxn;
	return 0;
}
