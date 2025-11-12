#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c,id;
	bool operator <(const node x)const
	{
		return abs(a-b)>abs(x.a-x.b);
	}
}a[100005];
int t,n,ans,cnta,cntb,vis[100005],cntc,dp[205][205];
pair<int,int>b[100005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n;
		ans=0;
		cnta=cntb=cntc=0;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].id=i;
			if(n>200)
			{
				ans+=a[i].c;
				a[i].a-=a[i].c;
				a[i].b-=a[i].c;
			} 
		}
		if (n>200)
		{
			sort(a+1,a+n+1);
			for (int i=1;i<=n;i++)
			{
				if (a[i].a>a[i].b&&cnta!=n/2||cntb==n/2)
				{
					cnta++;
					ans+=a[i].a;
					b[i]=make_pair(a[i].a,a[i].id);
					vis[a[i].id]=1;
				}
				else
				{
					cntb++;
					ans+=a[i].b;
					b[i]=make_pair(a[i].b,a[i].id);
					vis[a[i].id]=2;
				}
			}
			sort(b+1,b+n+1);
			int j_1=1,j_2=1,cnta_=0,cntb_=0;
			while (cnta_!=n/2)
			{
				if (vis[a[j_1].id]==1)
				{
					cnta_++;
				}
				j_1++;
			}
			while (cntb_!=n/2)
			{
				if (vis[a[j_2].id]==2)
				{
					cntb_++;
				}
				j_2++;
			}
			for (int i=1;i<=n/2;i++)
			{
				if (b[i].first<0&&cntc!=n/2)
				{
					cntc++;
					ans-=b[i].first;
					if (vis[b[i].second]==2)
					{
						vis[b[i].second]=3;
						cntb--;
						while (j_2<=n&&cntb_!=n/2)
						{
							if (vis[a[j_2].id]==2&&a[j_2].b>a[j_2].a)
							{
								cntb_++;
								ans+=a[j_2].b-a[j_2].a;
							}
							j_2++;
						}
					}
					else
					{
						vis[b[i].second]=3;
						cnta--;
						while (j_1<=n&&cnta_!=n/2)
						{
							if (vis[a[j_1].id]==2&&a[j_1].b>a[j_1].a)
							{
								cnta_++;
								ans+=a[j_1].b-a[j_1].a;
							}
							j_1++;
						}
					}
					
				}
			}
			cout<<ans<<'\n';
		}
		else
		{
			ans=0;
			memset(dp,0xc0,sizeof(dp));
			dp[0][0]=a[1].c;
			dp[1][0]=a[1].a;
			dp[0][1]=a[1].b;
			for (int i=2;i<=n;i++)
			{
				for (int j=n/2;j>=0;j--)
				{
					for (int k=n/2;k>=0;k--)
					{
						dp[j][k]=max(dp[j][k]+a[i].c,max((int)(j?dp[j-1][k]:0xc0c0c0c0c0c0c0c0)+a[i].a,(int)(k?dp[j][k-1]:0xc0c0c0c0c0c0c0c0)+a[i].b));
//						cout<<dp[j][k]<<' ';
					}
//					cout<<'\n';
				}
//				cout<<'\n';
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (i+j>=n/2)
						ans=max(ans,dp[i][j]);
//					cout<<ans<<' ';
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

