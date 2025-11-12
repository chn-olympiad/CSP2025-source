#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e4+114;

int f[MAXN];
int n,nn,m,k,c[100],a[100][MAXN];
struct road{
    int u,v,w;
} rd[1114514],nrd[1919810];
int ans = 0;
int ans2 = LONG_LONG_MAX;
int combine_road(int st){
    memset(nrd,0,sizeof(nrd));//problem
    int top = 0;
    for(int i = 1;i<=m;i++) nrd[++top] = rd[i]; 
    for(int i = 1;i<=k;i++){
        if(st & (1<<(k-i))){
            nn++;
            ans += c[i];
            for(int j = 1;j<=n;j++) nrd[++top] = {i+n,j,a[i][j]};
        }
    }
    return top;
}

bool cmp(road a,road b){
    return a.w<b.w;
}

int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
int flag = 1;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++) cin>>rd[i].u>>rd[i].v>>rd[i].w;
    for(int i = 1;i<=k;i++){
        cin>>c[i];
        if(c[i]) flag = 0;
        for(int j = 1;j<=n;j++) {
            cin>>a[i][j];
        }
    }

    if(flag){
        ans = 0;
        nn = n;
        int top = combine_road((1<<k)-1);
        for(int i = 1;i<=nn;i++) f[i] = i;
        sort(nrd+1,nrd+top+1,cmp);
        for(int j = 1;j<=top;j++){
            int u = nrd[j].u,v = nrd[j].v,w = nrd[j].w;
            int fu = find(u);
            int fv = find(v);
            if(fu == fv) continue;
            f[fu] = fv;
            ans += w;
//            cout<<u<<" "<<v<<" "<<w<<endl;
        }
        cout<<ans;
        return 0;
    }
    else{
        for(int i = 0;i<=(1<<k)-1;i++){
            ans = 0;
            nn = n;
            int top = combine_road(i);
            for(int i = 1;i<=nn;i++) f[i] = i;
            sort(nrd+1,nrd+top+1,cmp);
            for(int j = 1;j<=top;j++){
                int u = nrd[j].u,v = nrd[j].v,w = nrd[j].w;
                int fu = find(u);
                int fv = find(v);
                if(fu == fv) continue;
                f[fu] = fv;
                ans += w;
    //            cout<<u<<" "<<v<<" "<<w<<endl;
            }
            ans2 = min(ans2,ans);
        }
        cout<<ans2;
    }
}