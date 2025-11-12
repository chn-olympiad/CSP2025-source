#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M, K;

ll c[15], a[15][10005];

struct MSTEdge {
    int u, v;
    ll w;
} mstedge[6000005];

bool cmp(MSTEdge x, MSTEdge y)
{
    return x.w < y.w;
}

int fa[10005];

int find_father(int x)
{
    return fa[x] == x ? x : fa[x] = find_father(fa[x]);
}

void merge(int x, int y)
{
    int fx = find_father(x);
    int fy = find_father(y);
    fa[fx] = fy;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    scanf("%d %d %d", &N, &M, &K);
    if(K == 0) // MST
    {
        for(int i = 1; i <= M; ++ i)
            scanf("%d %d %lld", &mstedge[i].u, &mstedge[i].v, &mstedge[i].w);
        
        sort(mstedge + 1, mstedge + M + 1, cmp);
        for(int i = 1; i <= N; ++ i)
            fa[i] = i;
        
        ll sum_cost = 0;
        for(int i = 1; i <= M; ++ i)
        {
            if(find_father(mstedge[i].u) == find_father(mstedge[i].v)) continue;
            sum_cost += mstedge[i].w;
            merge(mstedge[i].u, mstedge[i].v);
        }

        printf("%lld\n", sum_cost);
    }
    else 
    {
        for(int i = 1; i <= M; ++ i)
        	scanf("%d %d %lld", &mstedge[i].u, &mstedge[i].v, &mstedge[i].w);

        bool flagA = true;
        for(int i = 1; i <= K; ++ i)
        {
            scanf("%lld", &c[i]);
            bool exist = false;
            for(int j = 1; j <= N; ++ j)
            {
            	scanf("%lld", &a[i][j]);
                if(a[i][j] == 0) exist = true;
            }
            if(!exist || c[i] != 0) flagA = false;
        }

        if(flagA && N <= 1000)
        {
	        for(int i = 1; i <= K; ++ i)
	        {
	        	for(int u = 1; u <= N; ++ u)
		        {
		        	for(int v = u + 1; v <= N; ++ v)
		        	{
		        		mstedge[++ M] = (MSTEdge) {u, v, a[i][u] + a[i][v]};
					}
				}
			}
			
			sort(mstedge + 1, mstedge + M + 1, cmp);
	        for(int i = 1; i <= N; ++ i)
	            fa[i] = i;
	        
	        ll sum_cost = 0;
	        for(int i = 1; i <= M; ++ i)
	        {
	            if(find_father(mstedge[i].u) == find_father(mstedge[i].v)) continue;
	            sum_cost += mstedge[i].w;
	            merge(mstedge[i].u, mstedge[i].v);
	        }
	
	        printf("%lld\n", sum_cost);
        }
        else
        	printf("I don't know how to solve this. :( \n");
    }
    
    return 0;
}