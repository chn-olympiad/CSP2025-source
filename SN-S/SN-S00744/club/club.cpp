#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,m,ans,cnt1,cnt2,cnt3,nw1,nw2,a[N][5],gr[N];
pair<int,int> b[N],c[N];
bool cmp(int u,int v)
{
	return u>v;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		m=n/2;
		ans=0;
		nw1=nw2=1;
		cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++)
		{
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			if (mx==a[i][1])
			{
				gr[i]=1;
				cnt1++;
			}
			else if (mx==a[i][2])
			{
				gr[i]=2;
				cnt2++;
			}
			else
			{
				gr[i]=3;
				cnt3++;
			}
		}
		if (cnt1<=m&&cnt2<=m&&cnt3<=m)
		{
			for(int i=1;i<=n;i++)
				ans+=a[i][gr[i]];
			cout<<ans<<"\n";
		}
		else if (cnt1>m)
		{
			for(int i=1;i<=n;i++)
			{
				b[i].first=abs(a[i][1]-a[i][2]);
				c[i].first=abs(a[i][1]-a[i][3]);
				b[i].second=c[i].second=i;
			}
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			for(;cnt1>m;cnt1--)
			{
				while(gr[b[nw1].second]!=1&&nw1<=n)
					nw1++;
				while(gr[c[nw2].second]!=1&&nw2<=n)
					nw2++;
				if (nw1<=n&&b[nw1].first<c[nw2].first&&cnt2<m)
				{
					cnt2++;
					gr[b[nw1].second]=2;
					nw1++;
				}
				else
				{
					cnt3++;
					gr[c[nw2].second]=3;
					nw2++;
				}
			}
			for(int i=1;i<=n;i++)
				ans+=a[i][gr[i]];
			cout<<ans<<"\n";
		}
		else if (cnt2>m)
		{
			for(int i=1;i<=n;i++)
			{
				b[i].first=abs(a[i][2]-a[i][1]);
				c[i].first=abs(a[i][2]-a[i][3]);
				b[i].second=c[i].second=i;
			}
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			for(;cnt2>m;cnt2--)
			{
				while(gr[b[nw1].second]!=2&&nw1<=n)
					nw1++;
				while(gr[c[nw2].second]!=2&&nw2<=n)
					nw2++;
				if (nw1<=n&&b[nw1].first<c[nw2].first&&cnt1<m)
				{
					cnt1++;
					gr[b[nw1].second]=1;
					nw1++;
				}
				else
				{
					cnt3++;
					gr[c[nw2].second]=3;
					nw2++;
				}
			}
			for(int i=1;i<=n;i++)
				ans+=a[i][gr[i]];
			cout<<ans<<"\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				b[i].first=abs(a[i][3]-a[i][1]);
				c[i].first=abs(a[i][3]-a[i][2]);
				b[i].second=c[i].second=i;
			}
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			for(;cnt3>m;cnt3--)
			{
				while(gr[b[nw1].second]!=3&&nw1<=n)
					nw1++;
				while(gr[c[nw2].second]!=3&&nw2<=n)
					nw2++;
				if (nw1<=n&&b[nw1].first<c[nw2].first&&cnt1<m)
				{
					cnt1++;
					gr[b[nw1].second]=1;
					nw1++;
				}
				else
				{
					cnt2++;
					gr[c[nw2].second]=2;
					nw2++;
				}
			}
			for(int i=1;i<=n;i++)
				ans+=a[i][gr[i]];
			cout<<ans<<"\n";
		}
	}
}
