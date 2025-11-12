#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int t,n,a[100005][4],s[4],b[4][100005],maxn;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int ijk=1;ijk<=t;ijk++)
	{
		cin>>n;
		maxn=0;
		memset(s,0,sizeof s);
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int k=max(a[i][1],max(a[i][2],a[i][3])),c;
			maxn+=k;
			if(k==a[i][1])
			{
				c=max(a[i][2],a[i][3]);
				b[1][++s[1]]=k-c;
			}
			else if(k==a[i][2])
			{
				c=max(a[i][1],a[i][3]);
				b[2][++s[2]]=k-c;
			}
			else
			{
				c=max(a[i][2],a[i][1]);
				b[3][++s[3]]=k-c;
			}
		}
		if(s[1]>n/2)
		{
			sort(b[1]+1,b[1]+s[1]+1);
			for(int i=1;i<=s[1]-n/2;i++)
			{
				maxn-=b[1][i];
			}
		}
		else if(s[2]>n/2)
		{
			sort(b[2]+1,b[2]+s[2]+1);
			for(int i=1;i<=s[2]-n/2;i++)
			{
				maxn-=b[2][i];
			}
		}
		else if(s[3]>n/2)
		{
			sort(b[3]+1,b[3]+s[3]+1);
			for(int i=1;i<=s[3]-n/2;i++)
			{
				maxn-=b[3][i];
			}
		}
		cout<<maxn<<'\n';
	}
}
