#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,w;
};
vector<node> m[1005];
bool vis[1005];
long long ans;
int n,m1,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m1>>k;
	
	for(int i=1;i<=m1;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		m[x].push_back({y,z});
		m[y].push_back({x,z});
	}
	for(int K=1;K<=k;K++)
	{
	    
		int c,a[1005],cnt=0;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int id=1003;
				for(int t=0;t<m[i].size();t++)
				{
					if(m[i][t].to==j)
					{
						id=t;
						break;
					}
				}
				if(m[i][id].w>a[i]+a[j])
				{
			    	cnt+=m[i][id].w-(a[i]+a[j]);
			    }
			}
		}
		if(cnt>c)
		{
		    for(int i=1;i<=n;i++)
		        for(int j=i+1;j<=n;j++)
			   	{
			   		m[i].push_back({j,a[i]+a[j]});
			   		m[j].push_back({i,a[i]+a[j]});
				}
	    	ans+=c;
		}
	}
	int cnt;
	while(cnt!=n-1)
	{
	    
		int minn=1000000005,a,b;
		for(int i=1;i<=n;i++)
    	{
    	    for(int j=0;j<m[i].size();j++)
	    	{
    	    	if((!vis[m[i][j].to])||(!vis[i]))
    	    	    if(m[i][j].w<minn)
    	            {
	    	   	        minn=m[i][j].w;
    	    	   	    a=i,b=m[i][j].to;
		    		}
    	   	}
	    }
	    vis[a]=true;
	    vis[b]=true;
	    cnt++;
	    ans+=minn;
	}
	cout<<ans;
	
	return 0;
}
