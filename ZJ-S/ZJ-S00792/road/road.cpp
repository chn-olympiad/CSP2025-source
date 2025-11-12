#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M,K,c0[12],cnt[1027],trans[1027];
ll ANS,ans[1027];
struct line{
    int u,v,w;
    bool operator < (const line other){return w < other.w;}
}L[1000010],T[12][10015],last[1027][10015],tank[3];
struct unif{
    int fa[10015],si[10015];
    int find(int now){
        if(fa[now] == now){return now;}
        return fa[now] = find(fa[now]);
    }
    bool mix(int x,int y){
        int tx = find(x),ty = find(y);
        if(tx == ty){return 0;}
        if(si[tx] < si[ty]){swap(tx,ty);}
        fa[ty] = tx;si[tx] += si[ty];
        return 1;
    }
    void clear(int N){
        memset(si,0,(N+3)<<2);
        for(int i = 1;i <= N;++i){fa[i] = i;}
    }
}U;
inline int lowbit(int x){return x&(-x);}
void kru(line *L,int A,line *T,int B,int tar){
    U.clear(N+K);
    int i = 1,j = 1;
    while(i <= A||j <= B){
        if(L[i].w < T[j].w){
            if(U.mix(L[i].u,L[i].v)){
                ans[tar] += L[i].w;
                last[tar][++cnt[tar]] = L[i];
            }
            ++i;
        }else{
            if(U.mix(T[j].u,T[j].v)){
                ans[tar] += T[j].w;
                last[tar][++cnt[tar]] = T[j];
            }
            ++j;
        }
    }
    last[tar][cnt[tar]+1] = {1,1,0x7f7f7f7f};
}
void solve(){
    cin >> N >> M >> K;
    for(int i = 1;i <= M;++i){cin >> L[i].u >> L[i].v >> L[i].w;}
    sort(L+1,L+1+M);tank[1] = L[M+1] = {1,1,0x7f7f7f7f};
    for(int i = 0;i < K;++i){
        cin >> c0[i];
        for(int j = 1;j <= N;++j){
            T[i][j] = {N+i+1,j,-1};
            cin >> T[i][j].w;
        }
        sort(T[i]+1,T[i]+1+N);
        T[K][N+1] = {1,1,0x7f7f7f7f};
    }    
    for(int i = 2;i < (1<<K);i <<= 1){trans[i] = trans[i>>1]+1;}
    for(int re = 1;re < (1<<K);++re){ans[re] = ans[re-lowbit(re)]+c0[trans[lowbit(re)]];}
    kru(L,M,tank,0,0);ANS = ans[0];
    for(int re = 1;re < (1<<K);++re){
        int from = re-lowbit(re),add = trans[lowbit(re)];
        kru(last[from],cnt[from],T[add],N,re);
        ANS = min(ans[re],ANS);
    }
    cout << ANS << '\n';
}
int main(){
    int st = clock();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T = 1;
    for(int i = 1;i <= T;++i){solve();}
    cerr << 1.0*(clock()-st)/CLOCKS_PER_SEC << "\n";
    return 0;
}
/* 
g++ -o road road.cpp -std=c++14 -g
g++ -o road road.cpp -std=c++14 -O2
*/