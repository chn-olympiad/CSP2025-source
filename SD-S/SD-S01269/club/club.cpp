#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> PII;
const int N=1e5+10,inf=1e9;
int n,m;
int a[N][5];
int mx[N],mx1[N],ci[N],ci1[N]; 
priority_queue<PII,vector<PII>,greater<PII> > q[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int mid=n/2;
		for(int i=1;i<=n;i++)
	        for(int j=1;j<=3;j++)
	            cin>>a[i][j];
	    for(int i=1;i<=n;i++)
	    {
	    	mx[i]=mx1[i]=ci[i]=ci1[i]=0;
	    	int minn=min(a[i][1],min(a[i][2],a[i][3]));
	    	int maxx=max(a[i][1],max(a[i][2],a[i][3]));
	    	for(int j=1;j<=3;j++)
	    	{
	    		if(!mx[i]&&a[i][j]==maxx) mx[i]=a[i][j],mx1[i]=j;
	    		else if(a[i][j]==a[i][1]+a[i][2]+a[i][3]-minn-maxx) ci[i]=a[i][j],ci1[i]=j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			q[mx1[i]].push({mx[i]-ci[i],i});
			if(q[mx1[i]].size()>mid) 
			{
				PII t=q[mx1[i]].top();
				q[mx1[i]].pop();
				int x=t.first,y=t.second;
				q[ci1[y]].push({inf,y});
			}
		}
		int ans=0;
		//for(int i=1;i<=n;i++) cout<<mx[i]<<" "<<ci[i]<<"\n";
		for(int i=1;i<=3;i++) 
			while(!q[i].empty()) ans+=a[q[i].top().second][i],q[i].pop();
		cout<<ans<<"\n";
	}
	return 0;
} 
