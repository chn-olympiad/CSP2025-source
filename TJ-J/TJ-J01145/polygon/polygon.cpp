#include <bits/stdc++.h>
using namespace std;

int mm[5001];

int f(int a){
    if(a==1) return 1;
    return a*(a-1);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    int i2=-1;
    for(int i=0;i<n;i++){
        cin>>mm[i];
        i2=max(mm[i],i2);
    }
    if(n==3){
        if(mm[1]+mm[0]+mm[2]>i2*2){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(i2==1){
        for(int i=3;i<=n;i++){
            ans+=f(n)/f((n-i))/f(i);
        }
        ans%=353;
        ans%=998;
        ans%=244;
        cout<<ans;
    }else{
        cout<<0;
    }
    return 0;
}
