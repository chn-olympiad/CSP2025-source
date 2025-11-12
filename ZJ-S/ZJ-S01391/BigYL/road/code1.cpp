#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define vector basic_string
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
constexpr int maxm=1e6+10,maxn=1e4+20,maxp=15;
struct edge{int l,r,val,id;}e[maxm],e2[maxn*10];
bool g[maxm];
int fa[maxn],cost[maxp];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
constexpr ll inf=1e18;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        e[i]=edge{x,y,z,0};
    }
    sort(e+1,e+m+1,[](edge pa,edge pb){return pa.val<pb.val;});
    for(int i=1;i<=n;i++)fa[i]=i;
    ll ans=inf;

    int mtot=0;
    for(int i=1;i<=m;i++){
        int pos1=find(e[i].l),pos2=find(e[i].r);
        if(pos1==pos2)continue;
        g[i]=1;
        e2[++mtot]=e[i];
        fa[pos1]=pos2;
        // ans+=e[i].val;
    }
    // debug2(ans);
    // int mtot=0;
    /*assert(mtot==n-1);
    */
    // m=n-1;
    m=mtot;
    for(int i=1;i<=mtot;i++)e[i]=e2[i];

    int tot=0;
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++){
            cin>>e2[++tot].val;
            e2[tot].l=n+i;e2[tot].r=j;
            e2[tot].id=i;
        }
    }
    sort(e2+1,e2+tot+1,[](edge pa,edge pb){return pa.val<pb.val;});
    for(int S=0;S<(1<<k);S++){
        ll res=0;
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int i=1;i<=k;i++){
            if((S>>(i-1))&1)res+=cost[i];
        }
        if(res>=ans)continue;
        int p1=1,p2=1,cnt=0,lmtcnt=n+__builtin_popcount(S);
        while(p1<=m and p2<=tot){
            if(res>=ans)break;
            if(cnt==lmtcnt)break;
            if((!((S>>(e2[p2].id-1))&1))){
                p2++;continue;
            }
            if(e[p1].val<e2[p2].val){
                int pos1=find(e[p1].l),pos2=find(e[p1].r);
                // debug1(pos1);debug2(pos2);
                if(pos1==pos2){
                    p1++;continue;
                }
                fa[pos1]=pos2;
                res+=e[p1].val;
                cnt++;
                // assert(g[p1]);
                p1++;
            }
            else{
                int pos1=find(e2[p2].l),pos2=find(e2[p2].r);
                if(pos1==pos2){
                    p2++;continue;
                }
                fa[pos1]=pos2;
                res+=e2[p2].val;
                cnt++;
                p2++;
            }
        }
        while(p1<=m){
            if(res>=ans)break;
            if(cnt==lmtcnt)break;
            int pos1=find(e[p1].l),pos2=find(e[p1].r);
            if(pos1==pos2){
                p1++;continue;
            }
            fa[pos1]=pos2;
            res+=e[p1].val;
            // assert(g[p1]);
            cnt++;
            p1++;
        }
        while(p2<=tot){
            if(res>=ans)break;
            if(cnt==lmtcnt)break;
            if((!((S>>(e2[p2].id-1))&1))){
                p2++;continue;
            }
            int pos1=find(e2[p2].l),pos2=find(e2[p2].r);
            if(pos1==pos2){
                p2++;continue;
            }
            fa[pos1]=pos2;
            res+=e2[p2].val;
            cnt++;
            p2++;
        }
        /*for(int i=1;i<=n;i++){
            assert(fa[i]==fa[1]);
        }*/
        ans=min(ans,res);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
g++ -std=c++14 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
*/