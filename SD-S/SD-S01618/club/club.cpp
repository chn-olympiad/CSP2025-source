#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100010][5],b[100010],c[5];
struct node{
	int id;
	int g;
}d[100010];
bool cmp(node a,node b)
{
	return a.g<b.g;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)d[i].id=i,d[i].g=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if((a[i][1]>=a[i][2])&&(a[i][1]>=a[i][3]))
			{
				b[i]=1;
				ans+=a[i][1];
				d[i].g=a[i][1]-max(a[i][2],a[i][3]);
			}
			else if((a[i][2]>=a[i][1])&&(a[i][2]>=a[i][3]))
			{
				b[i]=2;
				ans+=a[i][2];
				d[i].g=a[i][2]-max(a[i][1],a[i][3]);
			}
			else if((a[i][3]>=a[i][1])&&(a[i][3]>=a[i][2]))
			{
				b[i]=3;
				ans+=a[i][3];
				d[i].g=a[i][3]-max(a[i][1],a[i][2]);
			}
			c[b[i]]++;
		}
		for(int i=1;i<=3;i++)
		{
			if((c[i]*2)>n)
			{
				sort(d+1,d+n+1,cmp);
				int x=c[i]-(n/2LL),num=0;
				for(int j=1;j<=n;j++)
				{
					if(b[d[j].id]==i)
					{
						num++;
						ans-=d[j].g;
					}
					if(num==x)break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}












