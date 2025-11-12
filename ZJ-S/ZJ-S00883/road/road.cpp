#include<bits/stdc++.h>
using namespace std;
const int M = 1e6+10;
const int N = 1e4+20;
struct edge{
    int u,v,w;
}all[M],now[N*(10+1)],a[11][N];
bool cmp(edge a,edge b){
    return a.w < b.w;
}
int fa[N],c[11];
int n,m,k,E;
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
long long work(int vnum,int enm){
    for(int i = 1;i <= n + k;i++) fa[i] = i;
    sort(now+1,now+enm+1,cmp);
    int cnt = 0;
    long long ret = 0;
    for(int i = 1;i <= enm;i++){
        int a = find(now[i].u),b = find(now[i].v);
        if(a != b){
            cnt += 1;
            ret += now[i].w;
            fa[a] = b;
            if(cnt == vnum - 1) break;
        }
    }
    return ret;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++)
        scanf("%d%d%d",&all[i].u,&all[i].v,&all[i].w);
    sort(all+1,all+m+1,cmp);
    for(int i = 1;i <= n + k;i++) fa[i] = i;
    int cnt = 0;
    long long ans = 0;
    for(int i = 1;i <= m;i++){
        int a = find(all[i].u),b = find(all[i].v);
        if(a != b){
            cnt += 1;
            ans += all[i].w;
            fa[a] = b;
            now[++E] = all[i];
            if(cnt == n - 1) break;
        }
    }
    for(int i = 1;i <= E;i++) all[i] = now[i];
    for(int i = 1;i <= k;i++){
        scanf("%d",&c[i]);
        for(int j = 1;j <= n;j++){
            scanf("%d",&a[i][j].w);
            a[i][j].u = n+i;
            a[i][j].v = j;
        }
    }
    for(int i = 1;i < (1<<k);i++){
        E = n - 1;
        for(int j = 1;j <= E;j++) now[j] = all[j];
        long long tmp = 0;
        int tcnt = n;
        for(int j = 0;j < k;j++){
            if((i >> j) & 1){
                tmp += c[j+1];
                for(int l = 1;l <= n;l++) now[++E] = a[j+1][l];
                tcnt++;
            }
        }
        tmp += work(tcnt,E);
        ans = min(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}