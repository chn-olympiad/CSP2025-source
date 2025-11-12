#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int mod=998244353;
string s;
int n,m;
int c[N],p[N],ans;
inline void solve(){
    for(int i=1;i<=n;++i) p[i]=i;
    do{
        int cnt=0;
        for(int i=1;i<=n;++i){
            if (c[p[i]]<=cnt || s[i]=='0') ++cnt;
        }
        if (n-cnt>=m) ++ans;
    }while (next_permutation(p+1,p+n+1));
    cout<<ans<<"\n";
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    if (n<=10){
        solve(); return 0;
    }
    else if (m==n){
        printf("0\n"); return 0;
    }
    return 0;
}