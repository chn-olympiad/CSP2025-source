#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1100005;
int N,M,K,Fa[maxn],B_Len,C_Len,val[maxn];
struct YYZ{
    int x,y,w;
    bool operator <(const YYZ &B)const{return w<B.w;}
}A[maxn],B[maxn],C[maxn],D[maxn];
int Get_Fa(int x){return x==Fa[x]?x:Fa[x]=Get_Fa(Fa[x]);}
LL ans;
int ins(YYZ p){
    int fx=Get_Fa(p.x),fy=Get_Fa(p.y);
    int val=0;
    if(fx!=fy) Fa[fx]=fy,val=p.w;
    return val;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) Fa[i]=i;
    for(int i=1;i<=M;i++) cin>>A[i].x>>A[i].y>>A[i].w;
    for(int i=1;i<=K;i++) {
        cin>>val[i];
        for(int j=1,x;j<=N;j++) cin>>x,C[++C_Len]=(YYZ){i+N,j,x};
    }
    sort(A+1,A+1+M);
    sort(C+1,C+1+C_Len);
    for(int i=1;i<=M;i++){
        int fx=Get_Fa(A[i].x),fy=Get_Fa(A[i].y);
        if(fx!=fy){
            Fa[fx]=fy;
            B[++B_Len]=A[i];
        }
    }
    ans=4e18;
    B[++B_Len]=(YYZ){1,1,2000000000};
    for(int s=0;s<1<<K;s++){
        LL cur=0;
        for(int i=1;i<=N+K;i++) Fa[i]=i;
        for(int i=1;i<=K;i++) if(s>>(i-1)&1) cur+=val[i];
        int D_Len=0;
        for(int i=1;i<=C_Len;i++) if(s>>(C[i].x-N-1)&1) D[++D_Len]=C[i];
        for(int i=1,j=1;i<=B_Len;i++){
            while(j<=D_Len&&D[j].w<B[i].w) cur+=ins(D[j]),j++;
            cur+=ins(B[i]);
            if(cur>=ans) break;
        }
        ans=min(ans,cur);
    }
    cout<<ans<<'\n';
    return 0;
}