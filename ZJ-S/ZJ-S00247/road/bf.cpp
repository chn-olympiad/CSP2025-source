#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1100005;
int N,M,K,Fa[maxn],B_Len,val[maxn],C[12][10005];
struct YYZ{
    int x,y,w;
    bool operator <(const YYZ &B)const{return w<B.w;}
}A[maxn],B[maxn];
LL ans;
int Get_Fa(int x){return x==Fa[x]?x:Fa[x]=Get_Fa(Fa[x]);}
int ins(YYZ p){
    int fx=Get_Fa(p.x),fy=Get_Fa(p.y);
    int val=0;
    if(fx!=fy) Fa[fx]=fy,val=p.w;
    return val;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.ans","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) Fa[i]=i;
    for(int i=1;i<=M;i++) cin>>A[i].x>>A[i].y>>A[i].w;
    for(int i=1;i<=K;i++) {
        cin>>val[i];
        for(int j=1;j<=N;j++) cin>>C[i][j];
    }
    ans=4e18;
    for(int s=0;s<1<<K;s++){
        LL cur=0;B_Len=M;for(int i=1;i<=M;i++) B[i]=A[i];
        for(int i=1;i<=N+K;i++) Fa[i]=i;
        for(int i=1;i<=K;i++) if(s>>(i-1)&1) {
            cur+=val[i];
            for(int j=1;j<=N;j++) B[++B_Len]=(YYZ){i+N,j,C[i][j]};
        }
        sort(B+1,B+1+B_Len);
        for(int i=1;i<=B_Len;i++){
            cur+=ins(B[i]);
        }
        ans=min(ans,cur);
    }
    cout<<ans<<'\n';
    return 0;
}