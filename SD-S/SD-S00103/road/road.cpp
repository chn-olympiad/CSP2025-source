#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
};
bool cmp(node a,node b)
{
	return a.w<b.w;
}
const int M=1e4+10;
const int MM=2e6+5;
int fa[M];
node bian[MM];
int n,m,k;
int find(int u)
{
	if(u==fa[u])
	return u;
	else
	return fa[u]=find(fa[u]);
}
void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	fa[fu]=fv;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>bian[i].u>>bian[i].v>>bian[i].w;
	}
	int cnt=0;
	bool flag=true;
	int jiage[M];
	for(int i=1;i<=k;i++)
	{
	    int c;
	    cin>>c;
	    int xu;
	    memset(jiage,0,sizeof(jiage));
	    for(int j=1;j<=n;j++)
	    {
	    	cin>>jiage[j];
	    	if(c==0)
	    	{
	    		if(jiage[j]==0)
	    		{
	    			xu=j;
				}	
			}
		}
		for(int j=1;j<=n;j++)
		{
			bian[++m].u=xu;
			bian[m].v=j;
			bian[m].w=jiage[j];
		}
	}
	sort(bian+1,bian+m+1,cmp);
//	for(int i=1;i<=m;i++)
//	{
//		cout<<" "<<bian[i].u<<" "<<bian[i].v<<" "<<bian[i].w
//	}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(find(bian[i].u)!=find(bian[i].v))
			{
				merge(bian[i].u,bian[i].v);
				cnt++;
				ans+=bian[i].w;
				if(cnt==n-1)
				{
					cout<<ans;
					return 0;
				}
			}
		}
	return 0;
}
/*
4 4 1
1 4 6
4 2 5
2 3 7
3 4 4
0 1 3 100 5
*/
