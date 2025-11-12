#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout),ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define mset(a,v) memset(a,v,sizeof a)
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
bool c1;
const int NN=1e4+15,MM=1e6+5,KK=15,INF=0x3f3f3f3f3f3f3f3f,SS=(1<<10)+5;
int n,m,tot,k,c[KK],tp,ans;
struct Edge{
    signed u,v,w;//long long -> int
    void read(){
        cin>>u>>v>>w;
    }
    bool operator<(const Edge&t)const{
        return w<t.w;
    }
}edge[MM],edg[NN],dg[SS][NN<<1],cg[KK][NN],tmp[MM];//edg use NN,which is enough
int exval[SS],siz[SS];
// edg is ordered.dg is used to guibing sort.
struct DisJS{
    int fa[NN+KK],siz[NN+KK];
    void Init(){
        lop(i,1,n+k)fa[i]=i,siz[i]=1;
        return;
    }
    int Find(int x){
        if(x==fa[x])return x;
        return fa[x]=Find(fa[x]);
    }
    void Merge(int x,int y){
        int tx=Find(x),ty=Find(y);
        if(siz[tx]>siz[ty]){
            swap(tx,ty),swap(x,y);
        }
        fa[tx]=ty;
        siz[ty]+=siz[tx];
        // fa[Find(x)]=Find(/y);
        return;
    }
}djs;
int MST1(){
    int sum=0;
    sort(edge+1,edge+1+m);
    djs.Init();
    lop(i,1,m){
        int u=edge[i].u,v=edge[i].v;
        int tu=djs.Find(u),tv=djs.Find(v);
        if(tu==tv)continue;
        sum+=edge[i].w;
        edg[++tot]=edge[i];
        djs.Merge(u,v);
    }
    return sum;
}
void Integrate(int s,int x){//在s的基础上增加x
    // cerr<<s<<" "<<x<<"#####\n";
    int L1=1,L2=1;
    while(L1<=siz[s]&&L2<=n){
        if(dg[s][L1].w<cg[x][L2].w){
            tmp[L1+L2-1]=dg[s][L1];
            L1++;
        }else{
            tmp[L1+L2-1]=cg[x][L2];
            L2++;
        }
    }
    while(L1<=siz[s]){
        tmp[L1+L2-1]=dg[s][L1];
        L1++;
    }
    while(L2<=n){
        tmp[L1+L2-1]=cg[x][L2];
        L2++;
    }
    tp=siz[s]+n;
    // lop(i,1,tp)cerr<<tmp[i].w<<"@";cerr<<"\n";
    lop(i,1,tp)dg[s|(1<<x-1)][i]=tmp[i];
    return;
}
int MST2(int s){
    int sum=0;
    int oto=0;
    djs.Init();
    // cerr<<tp<<"###\n";
    // assert(tp==2*n-1);
    lop(i,1,tp){
        int u=dg[s][i].u,v=dg[s][i].v;
        int tu=djs.Find(u),tv=djs.Find(v);
        // cerr<<u<<" "<<v<<" "<<tu<<" "<<tv<<"***\n";;
        if(tu==tv)continue;
        sum+=dg[s][i].w;
        // cerr<<dg[s][i].w<<"%\n";
        tmp[++oto]=dg[s][i];
        djs.Merge(u,v);
    }
    lop(i,1,oto)dg[s][i]=tmp[i];
    siz[s]=oto;
    // assert(oto==n-1);
    return sum;
}
void Work(){
    cin>>n>>m>>k;
    lop(i,1,m)edge[i].read();
    ans=MST1();
    lop(i,1,k){
        cin>>c[i];
        lop(j,1,n){
            int a;cin>>a;
            cg[i][j]={n+i,j,a};
        }
        sort(cg[i]+1,cg[i]+1+n);
    }
    // assert(tot==n-1);
    lop(i,1,tot)dg[0][i]=edg[i];
    siz[0]=tot;
    // cout<<ans<<"#\n";
    lop(s,1,(1<<k)-1){
        exval[s]=exval[s^(s&-s)]+c[__lg(s&-s)+1];
        // cout<<exval[s]<<"#\n";
        Integrate(s-(s&-s),__lg(s&-s)+1);
        ans=min(ans,MST2(s)+exval[s]);
    }
    cout<<ans;
    return;
}
bool c2;
signed main(){
    // int Time=clock();
    // cerr<<abs(&c1-&c2)/1024.0/1024<<"\n";
    file("road");
    Work();
    // cerr<<"\n"<<1.0*(clock()-Time)/CLOCKS_PER_SEC;
    return 0;
}