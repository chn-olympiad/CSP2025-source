#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[100001][4],i,j,f[4];
ll s,p[100001],pp,ma;
void dfs(int i,ll s1,ll s2,ll s3,int t1,int t2,int t3)
{
	if(i>n)
	{
		s=s1+s2+s3;
		ma=max(ma,s);
		return;
	}
	if(t1<n/2)
	{
		dfs(i+1,s1+a[i][1],s2,s3,t1+1,t2,t3);
	}
	if(t2<n/2)
	{
		dfs(i+1,s1,s2+a[i][2],s3,t1,t2+1,t3);
	}
	if(t3<n/2)
	{
		dfs(i+1,s1,s2,s3+a[i][3],t1,t2,t3+1);
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ma=0;
		f[2]=f[3]=0;
		pp=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==1)p[++pp]=a[i][j];
				if(a[i][j]!=0)f[j]=1;
			}
		}
		if(f[2]==0&&f[3]==0)
		{
			sort(p+1,p+n+1);
			for(i=n-1;i>=n-n/2;i--)
			{
				p[n]+=p[i];
			}
			cout<<p[n]<<"\n";
			continue;
		}
		dfs(1,0,0,0,0,0,0);
		cout<<ma<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/
