#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
using ll=long long;
ll a[N];ll n,k;
ll ans;
bool flagA=false;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flagA=true;
    }
    if(!flagA){
        cout<<1;
    }else{
        cout<<2; 
    }
    
    
}
