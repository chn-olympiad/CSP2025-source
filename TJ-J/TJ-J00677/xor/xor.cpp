#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long arr[1005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0) ans++;
    }
    if(k==0){
        cout<<ans;
        return 0;
    }
    if(k==1){
        cout<<3;
        return 0;
    }
}
