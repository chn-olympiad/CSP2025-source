#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
constexpr int mod=998244353;
int n,m,c[15],p[15];
string s;
bool check() {
    int cnt=0,res=0;
    for(int i=1;i<=n;i++) {
        if(cnt>=c[p[i]]) {
            cnt++;
            continue;
        }
        if(s[i]=='1') res++;
        else cnt++;
    }
    return res>=m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) p[i]=i;
    int ans=0;
    do {
        if(check()) ans=(ans+1)%mod;
    } while(next_permutation(p+1,p+n+1));
    cout<<ans<<"\n";
    return 0;
}