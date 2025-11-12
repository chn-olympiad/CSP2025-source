#include <bits/stdc++.h>

using namespace std;

const int N=2005;
const int mxN=1e5+5;

int n,a[mxN][4],f[2][N][N],ans;

bool check1()
{
	for(int i=1;i<=n;i++)
		if(a[i][2]!=0||a[i][3]!=0) return 0;
	return 1;
}

int tp[mxN];

int getans1()
{
	for(int i=1;i<=n;i++) tp[i]=a[i][1];
	sort(tp+1,tp+n+1);
	int ans=0;
	for(int i=n;i>n/2;i--) ans+=tp[i];
	return ans;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		if(check1())
		{
			cout<<getans1()<<'\n';
			continue;
		}
		int p=1;
		for(int i=1;i<=n;i++)
		{
			for(int na=0;na<=min(i,n/2);na++)
			{
				for(int nb=0;nb<=min(i-na,n/2);nb++)
				{
					int nc=i-na-nb;
					if(nc>n/2) continue;
					if(na>0) f[p][na][nb]=max(f[p][na][nb],f[p^1][na-1][nb]+a[i][1]);
					if(nb>0) f[p][na][nb]=max(f[p][na][nb],f[p^1][na][nb-1]+a[i][2]);
					if(nc>0) f[p][na][nb]=max(f[p][na][nb],f[p^1][na][nb]+a[i][3]);
				}
			}
			p^=1;
		}
		int ans=0;
		p^=1;
		for(int na=0;na<=n/2;na++)
		{
			for(int nb=0;nb<=n/2;nb++)
			{
				if(n-na-nb<=n/2)
					ans=max(ans,f[p][na][nb]);
				f[0][na][nb]=f[1][na][nb]=0;
			}
		}
		cout<<ans<<'\n';

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
