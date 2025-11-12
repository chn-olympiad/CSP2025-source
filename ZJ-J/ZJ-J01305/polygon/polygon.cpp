#include<bits/stdc++.h>
using namespace std;
long long stick[5050],n,maxn=0;

void dfs(long long now,long long size,long long maxs,long long cnt)
{
	if(now>n)
	{
		if((size>maxs*2)&&(cnt>=3))
		{
			maxn+=1;
			maxn=maxn%998244353;
			//cout<<maxs<<' '<<size<<' '<<cnt<<endl;//dubug!!!
		}
		return;
	}
	dfs(now+1,size,maxs,cnt);
	if(stick[now]>maxs)
	{
		maxs=stick[now];
	}
	cnt+=1;
	size+=stick[now];
	dfs(now+1,size,maxs,cnt);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//memset(stick,0,sizeof(stick));
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>stick[i];
	}
	dfs(1,0,0,0);
	cout<<maxn;
	return 0;
}
