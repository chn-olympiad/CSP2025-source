#include<bits/stdc++.h>
using namespace std;

// #define int ll
#define file(jzc) freopen(#jzc".in","r",stdin),freopen(#jzc".out","w",stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define LB lower_bound
#define UB upper_bound
#define all(a) (a).begin(),(a).end()

using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
using tiii=tuple<int,int,int>;
using vi=vector<int>;
using vvi=vector<vi>;

template<typename T1,typename T2>
void chkmin(T1&x,const T2&y){if(y<x)x=y;}
template<typename T1,typename T2>
void chkmax(T1&x,const T2&y){if(x<y)x=y;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    int n=10000,m=1000000,k=10,V=1e9;
    cout<<n<<' '<<m<<' '<<k<<'\n';
    for(int i=1;i<=m;i++){
        int x=rng()%n+1,y=rng()%(n-1)+1;
        y+=y>=x;
        cout<<x<<' '<<y<<' '<<rng()%(V-200000000)+200000000<<'\n';
    }
    for(int i=1;i<=k;i++){
        cout<<rng()%V<<' ';
        for(int j=1;j<=n;j++)cout<<rng()%V<<' ';
        cout<<'\n';
    }
}

signed main(){
    // file();
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
}