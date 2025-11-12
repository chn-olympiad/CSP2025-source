#include<iostream>
#include<algorithm> 
#include<cstring>
#include<queue>
#define int long long
#define PII pair<int,int>
using namespace std;
const int INF = 1e9;
const int N = 1e5 +10;
inline int read(){
    int f =  1,x = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f *= -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return f * x;
}
void write(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9){
        write(x / 10);
    }
    putchar(x % 10);
}
int n,m,k;
int ans;
struct Graph{
    struct node{
        int to,nxt,val;
    }e[N << 1];
    int tot,head[N];
    void add(int u,int v,int w){
        e[++tot] = (node){v,head[u],w};
        head[u] = tot;
    }
    int dis[N];
    priority_queue<PII> q;
    void Dijkstra(int s){
        for(int i=1;i<=n;++i) dis[i] = INF;
        dis[s] = 0;
        q.push(PII{0,s});
        while(!q.empty()){
            int now = q.top().second;
            int d = -q.top().first;
            if(dis[now] != d) continue;
            for(int i=head[now];i;i=e[i].nxt){
                int to = e[i].to,val = e[i].val;
                if(dis[to] > d + val){
                    dis[to] = d + val;
                    q.push(PII{-dis[to],to});
                }
            }
        }
    }
    int fa[N],cnt=1;
    void Prim(int s){
    	for(int i=1;i<=n;++i) fa[i] = i;
    	q.push(PII{0,s});
        while(!q.empty()){
        	if(cnt == n) break;
            int now = q.top().second;
            int d = -q.top().first;
            for(int i=head[now];i;i=e[i].nxt){
            	int to = e[i].to,val = e[i].val; 
            	if(fa[to] != s){
            		ans += val;
            		fa[to] = s;
            		cnt ++;
            		q.push({-val,to});
				}
			}
        }
	}
}G;
int c;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    n = read(),m = read(),k = read();
    for(int i=1;i<=m;++i){
        int u = read(),v = read(),w = read();
        G.add(u,v,w);
        G.add(v,u,w);
    }
	for(int i=1;i<=k;++i){
		c = read();
		for(int j=1;j<=n;++j){
			int x;
			x = read();
			G.add(i,j,x);
			G.add(j,i,x);
		}
	}
	G.Prim(1);	
	cout << ans + c;				
    return 0;
}
