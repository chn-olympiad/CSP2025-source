// #define NDEBUG
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define ForD(i,j,k) for(int i=(j);i>=(k);i--)
#define int long long
#define endl '\n'
using namespace std;
bool Mbe;
multiset<int> A,B,C;
void solve(){
    int n; cin>>n;
    A.clear(),B.clear(),C.clear();
    int ans=0;
    For(i,1,n){
        int a,b,c; cin>>a>>b>>c;
        int mx=max({a,b,c});
        if(mx==a) A.insert(a-max(b,c));
        else if(mx==b) B.insert(b-max(a,c));
        else C.insert(c-max(a,b));
        ans+=mx;
    }
    while((int)A.size()>n/2) ans-=*A.begin(),A.erase(A.begin());
    while((int)B.size()>n/2) ans-=*B.begin(),B.erase(B.begin());
    while((int)C.size()>n/2) ans-=*C.begin(),C.erase(C.begin());
    cout<<ans<<endl;
}
bool Med;
signed main(){
    fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
    freopen("club.in","r",stdin), freopen("club.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--) solve();
    cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}