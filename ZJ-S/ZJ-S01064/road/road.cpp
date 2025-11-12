#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[200005],degree[200005],sum[200005];
int u[1000005],v[1000005],w[1000005];
int c[105],a[105][100005];
struct node{
    int x, y, w;
}edge[2000005];
int id[105];
int find(int x){
    if(fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
bool cmp(node c,node d){
    return c.w < d.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    int cnt = 0;
    for(int i = 1;i <= m;i++){
        cin >> u[i] >> v[i] >> w[i];
        //cout << cnt << " ";
        cnt++;
        edge[cnt].x = u[i];
        edge[cnt].y = v[i];
        edge[cnt].w = w[i];
    }
    //cout << cnt << " ";
    int minm = 0,num = 0;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    sort(edge + 1,edge + cnt + 1,cmp);
    for(int i = 1;i <= cnt;i++){
        int x = find(edge[i].x);
        int y = find(edge[i].y);
        if(x == y)continue;
        fa[x] = y;
        minm += edge[i].w;
    }
    int ans = 0;
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        ans = c[i];
        cnt = 0;
        for(int j = 1;j <= m;j++){
            cnt++;
            edge[cnt].x = u[j];
            edge[cnt].y = v[j];
            edge[cnt].w = w[j];
        }
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
            edge[cnt + j].x = n + 1;
            edge[cnt + j].y = j;
            edge[cnt + j].w = a[i][j];
        }
        for(int i = 1;i <= n + 1;i++){
            fa[i] = i;
        }
        sort(edge + 1,edge + cnt + n + 1,cmp);
        for(int i = 1;i <= cnt + n;i++){
            
            int x = find(edge[i].x);
            int y = find(edge[i].y);
            //cout << edge[i].w << " " << edge[i].x << " " << edge[i].y << '\n';
            if(x == y)continue;
            fa[x] = y;
            ans += edge[i].w;
            
        }
        //cout << ans << " ";
        if(ans < minm){
            num++;
            id[num] = i;
        }
    }
    //cout << minm << " ";
    //cout << num << " ";
    cnt = 0;
    for(int j = 1;j <= m;j++){
        cnt++;
        edge[cnt].x = u[j];
        edge[cnt].y = v[j];
        edge[cnt].w = w[j];
    }
    ans = 0;
    for(int i = 1;i <= num;i++){
        for(int j = 1;j <= n;j++){
            cnt++;
            edge[cnt].x = n + i;
            edge[cnt].y = j;
            edge[cnt].w = a[id[i]][j];
        }
        ans += c[id[i]];
        //cout << c[id[i]] << " ";
    }
    for(int i = 1;i <= n + num;i++){
        fa[i] = i;
    }
    //cout << ans << " ";
    //cout << n + num << " ";
    sort(edge + 1,edge + cnt + 1,cmp);
    for(int i = 1;i <= cnt;i++){
        int x = find(edge[i].x);
        int y = find(edge[i].y);
        if(x == y)continue;
        fa[x] = y;
        ans += edge[i].w;
        //cout << edge[i].w << " ";
        if(edge[i].x > n){
            //cout << edge[i].x << " ";
            degree[edge[i].x - n]++;
            sum[edge[i].x - n] = edge[i].w;
        }else if(edge[i].y > n){
            degree[edge[i].y - n]++;
            sum[edge[i].y - n] = edge[i].w;
        }
    }
    //cout << ans << " ";
    //cout << ans + 1<< " ";
    for(int i = 1;i <= num;i++){
        //cout << degree[i] << " ";
        if(degree[i] == 1){
            //cout << '*';
            ans -= c[id[i]];
            ans -= sum[i];
        }
    }
    cout << ans;
    return 0;
}
