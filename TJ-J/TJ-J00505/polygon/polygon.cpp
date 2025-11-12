#include<bits/stdc++.h>
using namespace std;
int n,stk[5005],num,ans;
int main(){
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stk[i];
    }
    sort(stk+1,stk+1+n);
    if(stk[3]>=stk[1]+stk[2]){
        cout<<0;
    }else{
        cout<<1;
    }
    return 0;
}
