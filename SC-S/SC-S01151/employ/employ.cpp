#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],flaga;
long long ans=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        if(!s[i])flaga=1;
    }
    if(!flaga){
        for(int i=1;i<=n;i++){
            ans*=i%998244353;
        }
        cout<<ans;
    }
    return 0;
};
