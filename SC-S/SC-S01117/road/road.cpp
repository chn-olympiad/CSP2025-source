#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
using ll=long long;
const int N=1e4+100,M=1e6+5,K=12,S=(1<<5)+5;
struct edge{
    int u,v,w;
    bool operator < (edge t){
        return w<t.w;
    }
}g[M];
int fa[N],h[N];
int find(int u){ return fa[u]==u?u:fa[u]=find(fa[u]); }
bool merge(int u,int v){
    u=find(u),v=find(v);
    if(u==v) return 0;
    if(h[u]>h[v]) swap(u,v);
    fa[u]=v;
    h[v]+=(h[u]==h[v]);
    return 1;
}
int n,m,k,ct;
edge a[K][N];
int c[N];
bool cpg(edge &a,edge &b){ return a.w<b.w; }
edge b[N*K],d[N*K];
edge sr1[S][N*K],sr2[S][N*K];
int len1[S],len2[S];
void srt(int l,int r){
    if(l==r) return ;
    int mid=(l+r)>>1;
    srt(l,mid),srt(mid+1,r);
    // db("srt %d to %d\n",l,r);
    int tl=(l-1)*n+1,ed1=mid*n;
    int tr=mid*n+1,ed2=r*n,t=(l-1)*n;
    while(tl<=ed1||tr<=ed2){
        if(tl<=ed1&&(tr>ed2||b[tl]<b[tr])) d[++t]=b[tl++];
        else d[++t]=b[tr++];
    }
    memcpy(b+(l-1)*n+1,d+(l-1)*n+1,(r-l+1)*n*sizeof (edge));
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        g[i]={u,v,w};
    }
    ll ans=0;
    sort(g+1,g+1+m,cpg);
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i)
        if(merge(g[i].u,g[i].v)){
            ans+=g[i].w;
            g[++ct]=g[i];
            // db("%d to %d,%d\n",g[i].u,g[i].v,g[i].w);
        }
    // db("ans=%lld\n",ans);
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j) cin>>a[i][j].w,a[i][j].u=j,a[i][j].v=i+n;
        sort(a[i]+1,a[i]+1+n,cpg);
    }
    int t1=(k>>1);
    for(int s=0;s<(1<<t1);++s){
        int tot=0;
        for(int j=1;j<=t1;++j)
            if(s>>(j-1)&1){
                for(int k=1;k<=n;++k) b[++tot]=a[j][k];
            }
        if(tot) srt(1,tot/n);
        for(int i=1;i<=tot;++i) sr1[s][i]=b[i];
        len1[s]=tot;
    }
    for(int s=0;s<(1<<(k-t1));++s){
        int ss=(s<<t1);
        int tot=0;
        for(int j=t1+1;j<=k;++j)
            if(ss>>(j-1)&1){
                for(int k=1;k<=n;++k) b[++tot]=a[j][k];
            }
        if(tot) srt(1,tot/n);
        for(int i=1;i<=tot;++i) sr2[s][i]=b[i];
        len2[s]=tot;
    }

    for(int s=1;s<(1<<k);++s){
        // db("s=%d-------\n",s);
        ll sum=0;
        int ct=n-1;
        int tot=0;
        for(int i=0;i<k;++i)
            if(s>>i&1){
                fa[n+i+1]=n+i+1,h[i+n+1]=0;
                sum+=c[i+1],++ct;
            }
            
        int tl=1,tr=1;
        int s1=s&((1<<t1)-1),s2=s>>t1;
        int dl=len1[s1],dr=len2[s2];
        while(tl<=dl||tr<=dr){
            if(tl<=dl&&(tr>dr||sr1[s1][tl]<sr2[s2][tr])){
                b[++tot]=sr1[s1][tl++];
            }else{
                b[++tot]=sr2[s2][tr++];
            }
        }


        if(sum>ans){
            continue;
        }
        for(int i=1;i<=n;++i) fa[i]=i,h[i]=0;
        tl=1,tr=1;
        while((tl<n||tr<=tot)&&ct){
            if(tl<n&&(tr>tot||g[tl]<b[tr])){
                if(merge(g[tl].u,g[tl].v)){
                    sum+=g[tl].w;
                    --ct;
                }
                ++tl;
            }else{
                if(merge(b[tr].u,b[tr].v)){
                    sum+=b[tr].w;
                    --ct;
                }
                ++tr;
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans<<"\n";
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}