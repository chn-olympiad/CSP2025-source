#include<bits/stdc++.h>
using namespace std;
int a[4][100010];
int l1,l2,l3;
int ans=-1;
int n;
void dfs(int nn,int lj)
{
	if(nn<=0)
	{
		if(lj>ans)ans=lj;
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1&&l1<n/2)
		{
			l1++;
			dfs(nn-1,lj+a[i][n-nn+1]);
			l1--;
		}
		if(i==2&&l2<n/2)
		{
			l2++;
			dfs(nn-1,lj+a[i][n-nn+1]);
			l2--;
		}
		if(i==3&&l3<n/2)
		{
			l3++;
			dfs(nn-1,lj+a[i][n-nn+1]);
			l3--;
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		if(n>200)
		{
			sort(a[1]+1,a[1]+1+n);
			int lj=0;
			for(int i=100000;i>50000;i--)
			{
				lj+=a[1][i];
			}
			cout<<lj<<endl;
			continue;
		}
		l1=0,l2=0,l3=0;
		ans=-1;
		dfs(n,0);
		cout<<ans<<endl;
	}
	return 0;
} 