#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N][5];
int cnt[5];
struct s{int ma,mal,cma,cmal,c;};
s p[N];
bool cmp(s x,s y)
{
	return x.c>y.c;
}
long long ans;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int ma=-0x3f3f3f3f,mal=0,mi=0x3f3f3f3f,mil=0;
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			for(int j=1;j<=3;j++)
			{
				if(ma<a[i][j])
				{
					ma=a[i][j];
					mal=j;
				}
				if(mi>a[i][j])
				{
					mi=a[i][j];
					mil=j;
				}
			}
			p[i].ma=ma;
			p[i].mal=mal;
			int cma,cmal;
			for(int j=1;j<=3;j++)
			{
				if(j!=mal&&j!=mil)
				{
					cma=a[i][j];
					cmal=j;
				}
			}
			p[i].cma=cma;
			p[i].cmal=cmal;
			p[i].c=ma-cma;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt[p[i].mal]>=n/2)
			{
				cnt[p[i].cmal]++;
				ans+=p[i].cma;
			}
			else
			{
				cnt[p[i].mal]++;
				ans+=p[i].ma;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
