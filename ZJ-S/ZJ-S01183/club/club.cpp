#include<bits/stdc++.h>
using namespace std;

#define int ll
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
using ai3=array<int,3>;

template<typename T1,typename T2>
void chkmin(T1&x,const T2&y){if(y<x)x=y;}
template<typename T1,typename T2>
void chkmax(T1&x,const T2&y){if(x<y)x=y;}

void solve(){
    int n;
    cin>>n;
    vector<ai3>a(n);
    for(int i=0;i<n;i++)for(int j:{0,1,2})cin>>a[i][j];
    array<int,3>cnt{};
    array<vi,3>v;
    vi b(n);
    int ans=0;
    for(int i=0;i<n;i++){
        int j=max_element(all(a[i]))-a[i].begin();
        int k=min_element(all(a[i]))-a[i].begin();
        b[i]=a[i][j]-(accumulate(all(a[i]),0)-a[i][j]-a[i][k]);
        cnt[j]++,v[j].pb(i),ans+=a[i][j];
    }
    int k=max_element(all(cnt))-cnt.begin();
    if(cnt[k]>n/2){
        sort(all(v[k]),[&](int x,int y){return b[x]<b[y];});
        int jzc=cnt[k]-n/2;
        for(int i=0;i<jzc;i++)ans-=b[v[k][i]];
    }
    cout<<ans<<'\n';
}

signed main(){
    file(club);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
}