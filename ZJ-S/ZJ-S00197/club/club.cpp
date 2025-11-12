#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
struct node{
    int a,b,c;
}p[N];
int w[N];
inline void solve(){
    int n,ans=0,now=0;
    int cnta=0,cntb=0,cntc=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>p[i].a>>p[i].b>>p[i].c;
    }
    for(int i=1;i<=n;++i){
        if (p[i].a>=p[i].b && p[i].a>=p[i].c){
            ++cnta; ans+=p[i].a;
        }
        else if (p[i].b>=p[i].a && p[i].b>=p[i].c){
            ++cntb; ans+=p[i].b;
        }
        else{
            ++cntc; ans+=p[i].c;
        }
    }
    if (cnta<=n/2 && cntb<=n/2 && cntc<=n/2){
        cout<<ans<<"\n";
        return;
    }
    for(int i=1;i<=n;++i){
        if (cnta>n/2 && p[i].a>=p[i].b && p[i].a>=p[i].c){
            w[++now]=p[i].a-max(p[i].b,p[i].c);
        }
        else if (cntb>n/2 && p[i].b>=p[i].a && p[i].b>=p[i].c){
            w[++now]=p[i].b-max(p[i].a,p[i].c);
        }
        else if (cntc>n/2 && p[i].c>=p[i].b && p[i].c>=p[i].a){
            w[++now]=p[i].c-max(p[i].a,p[i].b);
        }
    }
    sort(w+1,w+now+1);
    int t=max(cnta,max(cntb,cntc))-(n/2);
    for(int i=1;i<=t;++i){
        ans=ans-w[i];
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while (T--) solve();
    return 0; 
}