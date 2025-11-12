#include<bits/stdc++.h>
#define int long long
using namespace std;
struct sidee{
	int u,v,w;
	bool operator >(const sidee m) const{
		return w>m.w;
	}
};
int fa[100101];
vector<sidee> s[10001];
vector<sidee> country[11];
priority_queue<sidee,vector<sidee>,greater<sidee> > p;
int getfa(int i)
{
	if(fa[i]==i) return i;
	return fa[i]=getfa(fa[i]);
}
int cct(int a,int b)
{
	int aa=getfa(a);
	int bb=getfa(b);
	if(aa==bb) return -1;
	fa[aa]=bb;
	return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		s[u].push_back({u,v,w});
		s[v].push_back({v,u,w});
		p.push({u,v,w});
		
	}
	for(int i=1;i<=k;i++)
	{
		int ci;
		cin>>ci;
		for(int j=1;j<=n;j++)
		{
			int aj;
			cin>>aj;
			country[i].push_back({100000+i,j,aj});
			s[j].push_back({j,100000+i,aj});
			
		}
		for(int j=0;j<(int)country[i].size();j++)
		{
			for(int k1=j+1;k1<(int)country[i].size();k1++)
			{
				int ww=country[i][j].w+country[i][k1].w;
				int uu=country[i][j].u,vv=country[i][j].v;
				p.push({uu,vv,ww});
			}
		}
		
	}
	int totw=0;
	int p11=0;
	while(!p.empty())
	{
		sidee px=p.top();
		p.pop();
		if(cct(px.u,px.v)==-1) continue;
		else {totw+=px.w;p11++;}
//		cout<<px.w<<endl;
		if(p11==n) break;
		
	}
	cout<<totw;
	return 0;
}