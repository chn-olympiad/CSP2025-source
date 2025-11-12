// 最开始图连通
// 修复原有道路的代价已经给出
// 1e6?? 排序？？？
// k<=10
// 利用10这个性质
// 或者，考虑直接求原图最小生成树
// 然后2^10在外面
// 小心爆int
// 不行，必须在外面
// 考虑新增道路的变化
// 
// 考虑最开始把可能的新边也加进来
// 考虑删掉一些点是否更优秀
// 必须枚举删除的点是哪些？？
// 不管了
// ???
// 读错题目30分钟
// 是说你可以选择启动一个中转站，启动过后有新边
// 但是这个中转站不一定要
// 题意是不是更简单了
// 首先我都不一定选它所以它一定不在图中
// 你注意到10个乡镇不连通
// 特殊性质启示我们：
// 找到10个点每个点连出去最小代价的点
// 然后将他们两个视作一个点，然后跑最小生成树
#include<bits/stdc++.h>
using namespace std;
int clock_st = clock();
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
constexpr int N = 1e4+15;
constexpr int M = 1.5e6+5;
constexpr int MAXK = 15;
int n,m,K,tlt;
int a[MAXK][N],C[MAXK];
vector<pii>G[N];
struct Edge{
    int u,v,w;
    inline bool operator <(const Edge&o){
        return w < o.w;
    }
}E[M];
namespace DSU{
    int fa[N];
    int find(int x){
        if(fa[x]!=x)return fa[x]=find(fa[x]);
        return fa[x];
    }
    inline void unity(int x, int y){
        int fa1=find(x),fa2=find(y);
        if(fa1==fa2)return;
        fa[fa1]=fa2;
        return ;
    }
    inline void reset(){
        for(int i=1; i<=n+K; i++) fa[i]=i;
        return ;
    }
}
using namespace DSU;
namespace BF{
    LL ans = LLONG_MAX;
    inline int valid(int S, int u){
        return (S>>(u-n-1))&1 > 0;
    }
    inline void solve(int S){
        LL res = 0;
        int more = __builtin_popcount(S);
        for(int i=1; i<=K; i++){
            if((S>>i-1)&1) res += C[i];
        }
        reset();
        int cnt=0;
        for(int i=1,u,v,w,fa1,fa2; i<=tlt; i++){
            u=E[i].u, v=E[i].v, w=E[i].w;
            if(u>n && !valid(S,u)) continue;
            fa1=find(u),fa2=find(v);
            if(fa1==fa2)continue;
            unity(u,v);
            res += w, cnt++;
            if(cnt >= n+more-1) break;
            if(res > ans) return ;
        }
        ans = min(ans, res);
        return ;
    }
    inline void main(){
        sort(E+1,E+tlt+1);
        for(int S=0;S<(1<<K);S++){  // 枚举每个点选不选
            solve(S);
        }
        printf("%lld\n", ans);
        return ;
    }
}

signed main(){
    fastio;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> K;
    for(int i=1; i<=m; i++){
        int u,v,w;cin>>u>>v>>w;
        G[u].pb({v,w}),G[v].pb({u,w});
        E[++tlt] = {u,v,w};
    }
    for(int i=1; i<=K; i++){
        cin >> C[i];
        for(int j=1; j<=n; j++) cin >> a[i][j], E[++tlt] = {n+i, j, a[i][j]};
    }
    BF::main();
    return 0;
}
