#include<bits/stdc++.h>
using namespace std;
long long int n,a[100001][4],vis[4];
long long int dfs(int k)
{
	if(k>n) return 0;
    long long int value=-1;
	for(int j=1;j<=3;++j)
	{
		if(vis[j]>=n/2) continue;
		vis[j]++;
		long long int num=dfs(k+1);
		long long int x;
		x=num+a[k][j];
		value=max(value,x);
		vis[j]--;
	}
	return value;
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
    int t; 
	cin>>t;
	while(t--)
	{ 
		cin>>n;
	  for(long long int i=1;i<=n;++i) 
    	{
    		vis[i]=0;
		cin>>a[i][1];
	    cin>>a[i][2];
	    cin>>a[i][3];
    	}
	 cout<<dfs(1)<<'\n';
	}
	return 0;
} 