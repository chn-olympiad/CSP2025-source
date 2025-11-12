#include<bits/stdc++.h>
using namespace std;
const int maxn=10015;
const int maxk=100005;
const int maxm=1000005;
int n,m,k,tot,K,T;
int val[15];
int op[15];
struct node{
    int u,v,w;
}g;
node a[maxm], b[maxk];
long long res,ans;
bool cmp(node gg,node hh){
    return gg.w<hh.w;
}
int fa[maxn];
int getfa(int x){
    if(fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}
void work1(){
    for(int i=1;i<=(n+k);i++){
        fa[i]=i;
    }
    int p1=1, p2=1;
    int i=0;
    while(p2<=tot){
        if(op[b[p2].u-n]) break;
        p2++;
    }
    while(i<(T-1)){
        if( (p1<=m) && ((p2>tot)||(a[p1].w<b[p2].w)) ){
            //cout<<"11111"<<endl;
            getfa(a[p1].u);getfa(a[p1].v);
            if(fa[a[p1].u]!=fa[a[p1].v]){
                fa[fa[a[p1].v]]=fa[a[p1].u];
                i++; 
                res+=a[p1].w;
            }
            p1++;
            //cout<<"22222"<<endl;
            
        } 
        else{
            //cout<<"33333"<<endl;
            getfa(b[p2].u);getfa(b[p2].v);
            if(fa[b[p2].u]!=fa[b[p2].v]){
                fa[fa[b[p2].v]]=fa[b[p2].u];
                i++; 
                res+=b[p2].w;
            }
            p2++;
            while(p2<=tot){
                if(op[b[p2].u-n]) break;
                p2++;
            }
            //cout<<"44444"<<endl;
        }   
        //cout<<i<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                 
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=k;i++){
        scanf("%d",&val[i]);
        for(int j=1;j<=n;j++){
            tot++;
            b[tot].u=i+n;
            b[tot].v=j;
            scanf("%d",&b[tot].w);
        }       
    }
    sort(b+1,b+1+tot,cmp);
    K=(1<<k);
    int t=0;
    ans=20000000000000LL;
    for(int i=0;i<K;i++){
        T=n;
        res=0;
        for(int j=0;j<k;j++){
            t=(1<<j);
            if((t&i)!=0) op[j+1]=1,T++, res+=val[j+1];
            else op[j+1]=0;
        }
        if(res>=ans) continue;
        work1();
        ans=min(ans,res);
        if(ans==0) break;
    }
    printf("%lld",ans);
    return 0;
}