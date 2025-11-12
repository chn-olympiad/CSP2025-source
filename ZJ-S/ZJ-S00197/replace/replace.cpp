#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+5,K=1005;
vector<pair<int,int> > G[N];
int n,q;
inline void solve(){
    int cnt=0;
    string s[K],t[K],a,b;
    for(int i=1;i<=n;++i){
        cin>>s[i]>>t[i];
    }
    while (q--){
        int ans=0;
        cin>>a>>b;
        if (a.size()!=b.size()){
            cout<<0<<"\n"; continue;
        }
        for(int i=0;i<a.size();++i){
            for(int j=1;j<=n;++j){
                if (s[j].size()+i>a.size()) continue;
                string temp=a.substr(i,s[j].size());
                if (temp!=s[j]) continue;
                string now=a.substr(0,i)+t[j]+a.substr(i+s[j].size(),1+(a.size())-(i+s[j].size()));
                if (now==b) ++ans;
            }
        }
        cout<<ans<<"\n";
    }
}
inline void solve2(){
    string s,t;
    for(int i=1;i<=n;++i){
        cin>>s>>t;
        int cnta=0,cntb=0;
        for(int j=0;j<s.size();++j){
            if (s[j]=='b'){
                cnta=j; break;
            }
        }
        for(int j=0;j<t.size();++j){
            if (t[j]=='b'){
                cntb=j; break;
            }
        }
        G[cnta-cntb+5000000].push_back({cnta,s.size()-cnta-1});
    }
    while (q--){
        int ans=0;
        cin>>s>>t;
        if (s.size()!=t.size()){
            cout<<0<<"\n"; continue;
        }
        int cnta=0,cntb=0;
        for(int j=0;j<s.size();++j){
            if (s[j]=='b'){
                cnta=j; break;
            }
        }
        for(int j=0;j<t.size();++j){
            if (t[j]=='b'){
                cntb=j; break;
            }
        }
        for(auto [u,v]:G[cnta-cntb+5000000]){
            if (u<=cnta && v<=(s.size()-cnta-1)){
                ++ans;
            }
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    if (n<=1000 && q<=1000){
        solve();
        return 0;
    }
    else{
        solve2();
        return 0;
    }
    return 0;
}