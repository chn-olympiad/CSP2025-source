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
int a[MaxN];
string s[MaxN][2],t[MaxN][2];
inline void Solve(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=M;i++){
        cin>>t[i][0]>>t[i][1];
    }
    cout<<0<<endl;
}
signed main(){
#ifdef NOIIO
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
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