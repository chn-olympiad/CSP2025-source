#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII>a[100002];
struct{
	int l,r;
}kk[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(PII(v,w));
		a[v].push_back(PII(u,w));
	}
	int kw[20];
	for(int i=1;i<=k;i++)
	{
		int l;
		cin>>l;
		kw[i]=l;
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			a[n+i].push_back(PII(j,x));
			a[j].push_back(PII(n+i,x));
		}
	}
	bool kt[11];
	int yk=n;
	memset(kt,false,sizeof(kt));
	vector<int>z;
	bool bz[100001];
	memset(bz,false,sizeof(bz));
	bz[1]=true;
	z.push_back(1);
	int j=1;
	while(j<yk)
	{
		int l=1,r1=1,r2=1;
		bool e=false;
		int mini=1,minb=0x3f3f3f3f;		
		for(auto i:z)
		{
			int size=a[i].size();
			for(int t=0;t<size;t++)
			{
				int z=a[i][t].second;
				if(a[i][t].first>n)
				{
					if(kt[a[i][t].first-n])
					{
						
						if(z<minb&&!bz[a[i][t].first])
						{
							mini=a[i][t].first,minb=z;
							e=false;
						}
						continue;
					}
					z+=kw[a[i][t].first-n];
					if(z<minb&&!bz[a[i][t].first])
					{
						mini=a[i][t].first,minb=z;
						l=i;
						e=false;
					}
					continue;
				}
				if(z<minb&&!bz[a[i][t].first])
				{
					mini=a[i][t].first,minb=z;
					if(i>n)
					{
						r1=a[i][t].first;
						r2=i;
						e=true;
					}
					else
					{
						e=false;
					}
				}
			}
		}	
		if(mini>n&&!kt[mini])
		{
			kt[mini]=true;
			yk++;
			kk[mini-n].l=l;
			kk[mini-n].r=minb;
		}
		if(e)
		{
		int size=a[kk[r2-n].l].size();
			for(int t=0;t<size;t++)
			{
			if(a[kk[r2-n].l][t].first==r1)
				{
					ans-=kk[r2-n].r;
					ans+=min(kk[r2-n].r,a[kk[r2-n].l][t].second-minb);
				}
			}
		}
		j++;
		z.push_back(mini);
		ans+=minb;
		bz[mini]=true;
	}
	cout<<ans;
	return 0;
}