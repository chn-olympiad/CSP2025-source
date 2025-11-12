#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int x[2]={0};
    for(int i=0;i<n;i++)cin>>x[i];
    int ans=0;
    if(x[0]==k)ans++;
    if(x[1]==k)ans++;
    if(ans>0){
        cout<<ans;
        return 0;
    }
    else if(x[0]==x[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
