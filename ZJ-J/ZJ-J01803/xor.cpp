#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define VE vector
LL n,k,ans,sh,f=1;VE<LL>ar;VE<pair<LL,LL>>qj;
LL check(LL a,LL b){
    for(LL i=0;i<qj.size();i++){
        if(a<=qj[i].second&&b>=qj[i].first)return 0;
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;ar.resize(n);sh=n;
    for(LL i=0;i<n;i++){cin>>ar[i];if(ar[i]==k){ans++;sh--;qj.push_back({i,i});}if(ar[i]>1)f=0;}
    for(LL i=2;i<=n;i++){
        if(sh<=i)break;
        for(LL j=i-1;j<n;j++){
                LL an=ar[j-i];
            if(!check(j-i,i))continue;
            for(LL k=j-i+1;k<=j;k++){
                an^=ar[k];
            }
            if(an==k){qj.push_back({j-i,j});sh-=i;ans++;}
        }
    }
    cout<<ans;
}

