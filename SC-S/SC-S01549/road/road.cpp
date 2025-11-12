#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr bool online=1;
struct node{
    int l,r,v;
    inline bool operator<(const node&t){
        return v<t.v;
    }
}e[2000005];
int n,m,k,f[10015],ec,ep[12],ans,ant,ch[12];
inline void inif(){
    for(int i=1;i<=n+k;++i) f[i]=i;
}
inline int find(int p){
    return f[p]!=p?f[p]=find(f[p]):p;
}
inline bool merge(int l,int r){
    l=find(l); r=find(r);
    if(l==r) return 0;
    return f[l]=r,1;
}
vector<int>he[1ll<<10|2],ce;
signed main(){
    if(online)
        freopen("road.in","r",stdin),
        freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    /*
    数据范围有点神秘。
    首先，在原图中，不在最小生成树中的边一定不会进入最终的决策中。
    因此，我们理解为 m<=n。继续讨论这个略简单的问题。

    我们二进制压位枚举城市化哪些乡镇。
    这样时间复杂度是 2^k(n+nk)\log(n+nk)。
    我们假设 E=(n+nk) 吧： 2^kE\logE
    其实时间复杂度有点高，不太容易卡过去，不过常数是很小的，也有希望。

    类推一下前面的结论，一条边在只有城镇 1 的时候被抛弃了，
    在有更多城镇的时候也会被抛弃。
    这样子时间复杂度应该已经优化到 2^kn\logn 左右了。
    非常优秀，可以通过！

    考虑一下实现。首先直接删去最开始多余的那些边。
    然后二进制压位枚举，此时一定存在 logbit 是一个枚举过的城镇。
    我们记录每一次保留了哪些边，并将组成部分的边集合并起来。

    这样空间是 O(2^kn) 的，还好。
    */
    cin>>n>>m>>k; ec=m; ans=1e18;
    for(int i=1;i<=m;++i)
        cin>>e[i].l>>e[i].r>>e[i].v;
    sort(e+1,e+m+1); inif();
    for(int i=1;i<=m;++i)
        if(merge(e[i].l,e[i].r))
            he[0].emplace_back(i);
    for(int i=1;i<=k;++i){
        ep[i]=ec; cin>>ch[i-1];
        for(int j=1;j<=n;++j)
            ++ec,e[ec].l=n+i,
            e[ec].r=j,cin>>e[ec].v;
    }
    for(int c=1;c!=1ll<<k;++c){
        int lb=c&-c; ce=he[c^lb];
        int lp=round(log2(lb)+1);
        for(int i=1;i<=n;++i)
            ce.emplace_back(ep[lp]+i);
        sort(ce.begin(),ce.end(),[&](const int&l,const int&r){
            return e[l].v<e[r].v;
        });
        inif();
        for(int i:ce)
            if(merge(e[i].l,e[i].r))
                he[c].emplace_back(i);
    }
    for(int c=0;c!=1ll<<k;++c){
        ant=0;
        for(int i=0;i!=k;++i)
            if(c>>i&1) ant+=ch[i];
        for(int i:he[c]) ant+=e[i].v;
        ans=min(ans,ant);
    }
    /*
    考场上把 c 枚举范围整成 1~2^k-1 了。
    笑抽了......
    */
    cout<<ans<<endl;
    return 0; 
}
/*
passed this problem in 1h.
guess: Too young or Too simple? 
*/