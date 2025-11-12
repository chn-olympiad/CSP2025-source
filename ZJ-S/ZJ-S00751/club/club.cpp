#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N][4],n,t;
int ans;

void dfs(int c1,int c2,int c3,int p,int v)
{
	if(p==n+1)
	{
		 ans=max(ans,v);
		 return;
	}
	if(c1<n/2) dfs(c1+1,c2,c3,p+1,v+a[p][1]);
	if(c2<n/2) dfs(c1,c2+1,c3,p+1,v+a[p][2]);
	if(c3<n/2) dfs(c1,c2,c3+1,p+1,v+a[p][3]);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int aa=0;aa<t;aa++)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		dfs(0,0,0,1,0);
		cout<<ans<<endl;
	}
	return 0;
}