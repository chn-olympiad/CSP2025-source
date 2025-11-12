#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,a[N][4],na,nb,nc,ch[N][4];
int w[N][4],ans;
priority_queue<pair<int,int> > que[4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(ch,0,sizeof(ch));
		memset(w,0,sizeof(w));
		na=nb=nc=0;
		for(int i=0;i<=3;i++)
			while(que[i].size()) que[i].pop();
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) w[i][1]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) w[i][1]=2;
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) w[i][1]=3;
			if(a[i][1]>=a[i][2]&&a[i][1]<=a[i][3]) w[i][2]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]<=a[i][3]) w[i][2]=2;
			else if(a[i][3]>=a[i][1]&&a[i][3]<=a[i][2]) w[i][2]=3;
			else if(a[i][1]>=a[i][3]&&a[i][1]<=a[i][2]) w[i][2]=1;
			else if(a[i][2]>=a[i][3]&&a[i][2]<=a[i][1]) w[i][2]=2;
			else if(a[i][3]>=a[i][2]&&a[i][3]<=a[i][1]) w[i][2]=3;
			if(a[i][1]<=a[i][2]&&a[i][1]<=a[i][3]) w[i][3]=1;
			else if(a[i][2]<=a[i][1]&&a[i][2]<=a[i][3]) w[i][3]=2;
			else if(a[i][3]<=a[i][1]&&a[i][3]<=a[i][2]) w[i][3]=3;
			ch[i][1]=a[i][w[i][1]]-a[i][w[i][2]];;
			ch[i][2]=a[i][w[i][2]]-a[i][w[i][3]];	
		}
		for(int i=1;i<=n;i++)
		{
			
			if(w[i][1]==1)
			{
				que[1].push({-1*ch[i][1],i});
				ans+=a[i][1];
				if(na+1<=(n/2)) na++;
				else
				{
					int p=que[1].top().second;
					int cc=que[1].top().first*-1;
					ans-=cc;
					int p2=w[p][2];
					if(p2==2)
					{
						nb++;
						que[2].push({-1*ch[p][2],p});
					}
					else if(p2==3)
					{
						nc++;
						que[3].push({-1*ch[p][2],p});
					}
					que[1].pop();
				}
			}
			else if(w[i][1]==2)
			{
				que[2].push({-1*ch[i][1],i});
				ans+=a[i][2];
				if(nb+1<=n/2) nb++;
				else
				{
					int p=que[2].top().second;
					int cc=que[2].top().first*-1;
					ans-=cc;
					int p2=w[p][2];
					if(p2==1)
					{
						nb++;
						que[1].push({-1*ch[p][2],p});
					}
					else if(p2==3)
					{
						nc++;
						que[3].push({-1*ch[p][2],p});
					}
					que[2].pop();
				}
			}
			else if(w[i][1]==3)
			{
				que[3].push({-1*ch[i][3],i});
				ans+=a[i][3];
				if(nc+1<=n/2) nc++;
				else
				{
					int p=que[3].top().second;
					int cc=que[3].top().first*-1;
					ans-=cc;
					int p2=w[p][2];
					if(p2==1)
					{
						nb++;
						que[1].push({-1*ch[p][2],p});
					}
					else if(p2==2)
					{
						nc++;
						que[2].push({-1*ch[p][2],p});
					}
					que[3].pop();
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

