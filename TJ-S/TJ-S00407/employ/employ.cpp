#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n==m){
        for(int i=n;i>=1;i--){
            ans*=i;
            if(ans>=998244353) ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        for(int i=n-1;i>=1;i--){
            ans*=i;
            if(ans>=998244353) ans%=998244353;
        }
        ans*=(n-1);
        if(ans>=998244353) ans%=998244353;
        cout<<ans;
        return 0;
    }
    else{
        for(int i=n;i>=1;i--){
            ans*=i;
            if(ans>=998244353) ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
}
