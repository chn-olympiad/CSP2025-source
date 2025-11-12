#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+500;
ll T,n,a[N][3];
ll slv(ll x,ll y,ll z){
    ll ans=0;vector<ll>d;
    for(ll i=1,v1,v2;i<=n;i++){
        v1=a[i][x],v2=max(a[i][y],a[i][z]);
        ans+=max(v1,v2);
        if(v1>v2)d.push_back(v1-v2);
    }sort(d.begin(),d.end(),greater<ll>());
    while(d.size()>n/2)ans-=d.back(),d.pop_back();
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(cin>>T;T--;){
        cin>>n;
        for(ll i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        cout<<min({slv(0,1,2),slv(1,0,2),slv(2,0,1)})<<"\n";
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//git config --global --add safe.directory D:/work