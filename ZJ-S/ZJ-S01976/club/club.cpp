#include<bits/stdc++.h>
using namespace std;
int t,n,ans,mx;
multiset<int>s[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;mx=ans=0;
        s[0].clear(),s[1].clear(),s[2].clear();
        for(int i=1;i<=n;i++){
            int x,y,z,d;cin>>x>>y>>z;d=max(max(x,y),z);
            ans+=d;
            if(d==x){s[0].insert(x-max(y,z));continue;}
            if(d==y){s[1].insert(y-max(x,z));continue;}
            if(d==z){s[2].insert(z-max(x,y));continue;}
        }
        while(s[0].size()>n/2){ans-=*s[0].begin();s[0].erase(s[0].begin());}
        while(s[1].size()>n/2){ans-=*s[1].begin();s[1].erase(s[1].begin());}
        while(s[2].size()>n/2){ans-=*s[2].begin();s[2].erase(s[2].begin());}
        cout<<ans<<'\n';
    }
    return 0;
}
