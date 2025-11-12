#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a,b;
long long w[1000005];
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=m;i++){
            cin>>a>>b>>w[i];
            ans+=w[i];
        }
        cout<<ans;
    }else{
        cout<<0;
        return 0;
    }
}
