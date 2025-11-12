#include<bits/stdc++.h>
using namespace std;
#define NOIIO
// #define MULTI_CASES
#define ll long long 
// #define int ll
#define endl '\n'
#define vi vector<int>
#define PII pair<int,int>
const int MaxN=4e5+100;
const int INF=1e9;
const int mod=1e9+7;
int N,M,T=1;
int K;
int a[MaxN];
vector<PII> G1[MaxN];
inline void Solve(){
    cin>>N>>M>>K;
    int sum=0;
    for(int i=1;i<=M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
        G1[u].push_back({v,w});
        G1[v].push_back({u,w});
    }
    if(K==0){
        cout<<sum<<endl;
        return ;
    }

}
signed main(){
#ifdef NOIIO
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#ifdef MULTI_CASES
    cin>>T;
    while(T--)
#endif
        Solve();
    return 0;
}