//SN-S00636 蔡铭禹 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20],fa[10010],yq[20][10010],ww[1010][1010];
//vector<int> vec[10010];

struct node
{
	int x,y,w;
};

vector<node> vec;

bool cmp(node x,node y)
{
	return x.w<y.w;
}

int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

int kru()
{
	sort(vec.begin(),vec.end(),cmp);
	int cnt=0,tot=0,ans=0;
	while(cnt!=n-1)
	{
		int ff=vec[tot].x;
		int fl=vec[tot].y;
		ff=find(ff);
		fl=find(fl);
		if(ff==fl) 
		{
			tot++;
			continue;
		}
		cnt++;
		ans+=vec[tot].w;
		fa[ff]=fl;
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	memset(ww,0x7f,sizeof(ww));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
//		vec[u].push_back(v);
//		vec[v].push_back(u);
		vec.push_back({u,v,w});
		ww[u][v]=ww[v][u]=w;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>yq[i][j];
		}
	}
	vector<node> tp;
	for(auto v:vec) tp.push_back(v);
	if(k==0) cout<<kru();
	else
	{
		int ans=0x7f7f7f7f7f7f7f7f;
		for(int i=0;i<(1<<k);i++)
		{
			vec.clear();
			for(auto v:tp) vec.push_back(v);
			int sum=0;
			for(int j=1;j<=k;j++)
			{
				if(i&(1<<(j-1)))
				{
					sum+=c[j];
					for(int p=1;p<=n;p++)
					{
						for(int l=1;l<=n;l++)
						{
							if(yq[j][p]+yq[j][l]<ww[p][l]) vec.push_back({p,l,yq[j][p]+yq[j][l]});
						}
					}
				}
			}
			for(int i=1;i<=n;i++) fa[i]=i;
			sum+=kru();
			ans=min(ans,sum);
		}
		cout<<ans;
	}
	return 0;
}
