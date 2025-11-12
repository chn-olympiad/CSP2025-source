#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5005],vis[5005]={0},n;
int cnt=0;
void dfs(int ma,int sum,int w)
{
	if(w>=3&&sum>ma*2)
		cnt++;
	if(w>=n)
		return;
	for(int i=0;i<n;i++)
	{
		if(vis[i]||a[i]<=ma)
			continue;
		vis[i]=true;
		dfs(a[i],sum+a[i],w+1);
		vis[i]=false;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	dfs(0,0,0);
	printf("%d",cnt);
	return 0;
}

