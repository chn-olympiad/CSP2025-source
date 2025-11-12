#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int T,maxans=0,ans=0,n;
int c[maxn][5],sum[5];
void solve(int a[maxn][5],int r)
{
	if(r>n)
	{
		maxans=max(maxans,ans);
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			if(sum[i]>=n/2)
			{
				continue;
			}
			ans+=a[r][i];
			sum[i]++;
			solve(a,r+1);
			ans-=a[r][i];
			sum[i]--;
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//cin.tie(0);
	//ios::sync_with_stdio(0);
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i][1]>>c[i][2]>>c[i][3];
		}
		maxans=0;
		ans=0;
		memset(sum,0,sizeof(sum));
		solve(c,1);
		cout<<maxans<<"\n";
	}
 	return 0;
}
