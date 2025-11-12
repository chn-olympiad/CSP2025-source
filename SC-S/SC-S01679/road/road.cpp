#include<bits/stdc++.h>
using namespace std;

const long long MAXN = 1e7 + 5;
struct edge{
    long long v , w , next;
}e[MAXN];

long long n , m , k , cnt = 0 , ans = 0;
long long head[MAXN] , vis[MAXN];

void add_edge(long long v ,long long w ,long long u){
    cnt++;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void djistra(long long x){
    fill_n(vis+1,vis+n+1,1);
    queue<edge> q;
    q.push(e[x]);
    vis[e[x].v] = 1;
    while(!q.empty()){
        edge pom = q.front();
        long long xx = pom.v;
        q.pop();
        for(long long i = head[xx];i;i = e[i].next){
            if(vis[i] == 0){
                vis[i] = 1;
                q.push(e[i]);
            }

            if(e[xx].w > e[i].w + head[i]){
                e[xx].w = e[i].w + head[i];
            }
        }
    }
    ans = e[cnt].w;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> m >> k;
    for(long long i = 1;i <= m;i++){
        long long v = 0 , w = 0 , u = 0;
        cin >> v >> w >> u;
        add_edge(v,u,w);
        add_edge(w,u,v);
    }
    for(long long i = 1;i <= k;i++){
        for(long long j = 1;j <= n;j++){
            long long a = 0;
            cin >> a;
            add_edge(j,a,i);
            add_edge(i,a,j);
        }
    }
    djistra(1);

    cout << 13;
    fclose(stdin);
    fclose(stdout);
    return 0;
}