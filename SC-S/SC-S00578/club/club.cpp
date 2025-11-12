#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,a[N][4],ans=0; 
vector<int> b[4];

void solve()
{
	ans=0;
	for(int i=1;i<=3;i++)
	{
		b[i].clear();
	}

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int max1=0,max2=0;
		a[i][0]=-1;
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][max1]<a[i][j])
			{
				max1=j;
			}
		}
		for(int j=1;j<=3;j++)
		{
			if(j!=max1 && a[i][max2]<a[i][j])
			{
				max2=j;
			}
		}
		ans+=a[i][max1];
		b[max1].push_back(a[i][max1]-a[i][max2]);
	}
	for(int i=1;i<=3;i++)
	{
		if(b[i].size()>n/2)
		{
			sort(b[i].begin(),b[i].end());
			for(int j=0;j<b[i].size()-n/2;j++)
			{
				ans-=b[i][j];
			}
			break;
		}
	}

	printf("%d\n",ans);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}