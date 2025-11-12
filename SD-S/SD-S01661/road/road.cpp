#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e6+5;
typedef long long ll;
//int head[N],cnt;
//struct _nod{
//    int next,v,w;
//} ed[4*N];
//void add(int x,int y,int w){
//    ed[++cnt].w=w;
//    ed[cnt].v=y;
//    ed[cnt].next=head[x];
//    head[x]=cnt;
//}
int n,m,k,c[12][N],f[N];
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
void init(){
//    memset(head,-1,sizeof head);
    for(int i=1;i<=n;i++) f[i]=i;
}
struct node{
    int u,v,w;
    bool operator<(const node& b)const{
        return w>b.w;
    }
};
priority_queue<node> q;
ll kruskal(){
    ll ans=0;
    while(!q.empty()){
        node s=q.top();
//        cout<<s.u<<" "<<s.v<<" "<<s.w<<"\n";
        q.pop();
        int fx=find(s.u),fy=find(s.v);
//        cout<<fx<<" "<<fy<<"\n";
        if(fx!=fy){
            ans+=s.w;
            f[fx]=fy;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
//        add(x,y,z);
        q.push({x,y,z});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
            q.push({i,j,0});
        } 
    }
    cout<<(kruskal());
    return 0;
}

