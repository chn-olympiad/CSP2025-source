//西安市曲江第一中学
//王钰皓 SN-S00528 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e4+10;
const int M=3e6+10;

struct EDGE
{
    int u,v,w;
//    bool div;//1->yuanbian 0->houjiabian
    //一旦插入了新的点，那么相当于是插入了很多新边，使用多个queue维护 
    //因为如果一旦选取加入新的边，说明A->B的路径代价过大 

    bool operator <(const EDGE& b) const 
    {
        return this->w<b.w;
    }
}E[M];

int cnt;

inline void add(int u,int v,int w)
{
    E[++cnt]={u,v,w};
}

int fa[N];
int find(int x)
{
    return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}

int n,m,k;
int a[12][N],c[12];

ll ans;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>m>>k;

    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }

    for(int i=1;i<=n;++i)
        fa[i]=i;
        
    for(int i=1;i<=k;++i)
    {
    	int tsj;
    	cin>>c[i];
    	
    	for(int j=1;j<=n;++j)
    	{
    		cin>>a[i][j];
    		if(a[i][j]==0)
    		{
    			tsj=j;
			}
		}
		
		for(int j=1;j<=n;++j)
		{
			if(tsj==j)
				continue;
				
			add(tsj,j,a[i][j]);
		}
	}
    //ks
    sort(E+1,E+cnt);
    
    for(int i=1,tot=0;i<=cnt;++i)
    {
        int a=find(E[i].u),b=find(E[i].v);

        if(a!=b)
        {
            ans+=E[i].w;
            fa[a]=b;

            ++tot;
            if(tot==n+1)
            {
                break;
            }
        }
    }

    cout<<ans;

    return 0;
}
