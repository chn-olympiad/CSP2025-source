#include<bits/stdc++.h>
using namespace std;
int a[100001][4],cnt[4],p[4][100001],s[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans,mx;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=3;k++)
				cin>>a[j][k];
		for(int j=1;j<=3;j++)
			cnt[j]=0;
		ans=0;
		for(int j=1;j<=n;j++)
		{
			mx=1;
			for(int k=2;k<=3;k++)
				if(a[j][k]>a[j][mx])
					mx=k;
			ans+=a[j][mx];
			p[mx][++cnt[mx]]=j;
		}
		for(int j=1;j<=3;j++)
			if(cnt[j]>n/2)
			{
				for(int k=1;k<=cnt[j];k++)
				{
					s[k]=2e9;
					for(int l=1;l<=3;l++)
						if(l!=j)
							s[k]=min(s[k],a[p[j][k]][j]-a[p[j][k]][l]);
				}
				sort(s+1,s+cnt[j]+1);
				for(int k=1;k<=cnt[j]-n/2;k++)
					ans-=s[k];
			}
		cout<<ans<<endl;
	}
	return 0;
}
