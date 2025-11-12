#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int mod=998244353;
int a[N],dp[N][N],mx[N];
int n,ans,cnt2;
int head[N],cnt;
//dis[N]
int vis[N];
struct Node{
    int u,dis;
};
queue<Node> q;
struct Edge{
    int next,w,to;
}G[N*2];
void add(int u,int v,int w){
    G[cnt].to=v;
    G[cnt].next=head[u];
    G[cnt].w=w;
    head[u]=cnt++;
}
void BFS(int s){
    //memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    q.push({s,0});
    //dis[s]=0;
    int maxx=0,dis=0;
    cnt2=1;
    while (!q.empty()){
        int u=q.front().u;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=G[i].next){
            int v=G[i].to;
            dis+=G[i].w;
            cnt2++;
            maxx=max(maxx,a[i]);
            if (dis>=maxx*2 && cnt2>=3) ans++;
            ans%=mod;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(head,-1,sizeof(head));
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=3){
        if (n==2 || n==1) cout<<0<<endl;
        else{
            int maxx=0,sum=0;
            for (int i=1;i<=n;i++){
                maxx=max(maxx,a[i]);
                sum+=a[i];
            }
            if (sum>maxx*2) cout<<1<<endl;
            else cout<<0;
        }
        return 0;
    }
    if (n==4){
        int ans=0;
        for (int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i!=j && j!=k && i!=k){
                        if (a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
                            ans++;
                        }
                    }
                }
            }
        }
        if (a[1]+a[2]+a[3]+a[4]>max({a[1],a[2],a[3],a[4]})*2) ans++;
        cout<<ans;
        return 0;
    }
    if (n==5){
        int ans=0;
        for (int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i!=j && j!=k && i!=k){
                        if (a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int x=k+1;x<=n;x++){
                        if (a[i]+a[j]+a[k]+a[x]>max({a[i],a[j],a[k],a[x]})*2){
                            ans++;
                        }
                    }
                }
            }
        }
        if (a[1]+a[2]+a[3]+a[4]+a[5]>max({a[1],a[2],a[3],a[4],a[5]})*2) ans++;
        cout<<ans;
        return 0;
    }
    if (n==6){
        int ans=0;
        for (int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i!=j && j!=k && i!=k){
                        if (a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int x=k+1;x<=n;x++){
                        if (a[i]+a[j]+a[k]+a[x]>max({a[i],a[j],a[k],a[x]})*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int x=k+1;x<=n;x++){
                        for (int _1=x+1;_1<=n;_1++){
                        if (a[i]+a[j]+a[k]+a[x]+a[_1]>max({a[i],a[j],a[k],a[x],a[_1]})*2){
                            ans++;
                        }
                        }
                    }
                }
            }
        }
        if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>max({a[1],a[2],a[3],a[4],a[5],a[6]})*2) ans++;
        cout<<ans;
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            add(i,j,a[i]+a[j]);
            add(j,i,a[i]+a[j]);
        }
    }
    for (int i=1;i<=n;i++){
        BFS(a[i]);
    }
    cout<<(int)ceil(1.0*ans/n)%mod;
    return 0;
}
