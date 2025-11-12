#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1005];
bool flag=1;
long long ans1=0,ans2=1,ans3=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    ans1=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) flag=0;
        else if(a[i]==0) ans1--;
    }
    if(flag==1){
        for(int i=ans1;i>=1;i--){
            ans2*=i;
            if(ans2>=998244353) ans2=ans2%998244353;
        }
        cout<<ans2;
        return 0;
    }
    else if(n==3){
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
}
