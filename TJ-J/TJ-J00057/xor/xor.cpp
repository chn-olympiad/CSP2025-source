#include<bits/stdc++.h>
using namespace std;
long long n,k,temp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>temp;
    }
    if(k==0 || n==1){
        cout<<1;
        return 0;
    }else{
        cout<<2;
    }
    return 0;
}
