#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],ans,vis[5005],id2[5005];
void dfs(int x,int s)
{
	if(x==s+1)
	{
		int sum=0,ma=0;
		for(int i=1;i<=s;i++)
		{
			ma=max(ma,b[i]);	
			sum+=b[i];
		}
		if(sum>ma*2)
		{
			for(int i=1;i<=s;i++)
			{
				cout<<b[i]<<" ";
			}
			cout<<endl;
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)continue;
		if(a[i]<b[x-1])continue;
		if(i<id2[x-1])continue;
		b[x]=a[i];
		id2[x]=i;
		vis[i]=1;
		dfs(x+1,s);
		vis[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(1,i);
		//for(int j=1;j<=n;j++)vis[j]=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
