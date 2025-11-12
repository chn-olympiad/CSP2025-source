#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e6+20;
int u,v,w,n,k,m,fa[N];
long long ans,cnt=1;
int vis[N];
struct node{
    int u,v;
    long long w;
    bool f;
    int x;//是否为特殊边 以及所属乡镇编号
    friend bool operator<(const node &a,const node &b){
        return a.w>b.w;
    }
};
priority_queue<node> q;
int get_fa(int x){
    return ((fa[x]==x)?x:fa[x]=get_fa(fa[x]));
}
void merge(int x,int y,int w){
    int xx=get_fa(x),yy=get_fa(y);
    fa[xx]=yy;
    ans+=w;
    
    return ;
}
long long a[N][20],c[N];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        q.push((node){u,v,w,0,0});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j],q.push((node){i+n,j,a[i][j]+c[i],1,i});
    }
    while(cnt<n){//已连通的城市个数<n
        node now=q.top();
        int u=now.u,v=now.v;
        long long w=now.w;
        q.pop();
        if(now.f==0){
            int xx=get_fa(u),yy=get_fa(v);
            if(xx==yy) continue;
            if(xx!=yy) cnt++;//已连通的城市个数++
            merge(u,v,w);
            fa[xx]=yy;
        }else {
            int xx=get_fa(u),yy=get_fa(v);
            
            if(xx==yy) continue;
            int i=now.x;
            if(vis[i]==0){//第一次访问到该城镇
                for(int j=1;j<=n;j++){
                    if(j==v) continue;
                    q.push((node){v,j,a[i][j]+w,1,i});
                }
                vis[i]=1;
            }else if(u<=n){//第二次->产生作用
                merge(u,i+n,0);
                merge(i+n,v,w);
                cnt++;
                for(int j=1;j<=n;j++){
                    if(j==u||j==v) continue;
                    q.push((node){i+n,j,a[i][j],0,0});
                }
                    
            }
        }

    }
    cout<<ans<<"\n";
    return 0;
}