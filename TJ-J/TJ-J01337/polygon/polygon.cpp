#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010];
int main(){
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    long long ans=0;
    for(int i=3;i<=n;i++){
        if(b[i]>a[i]*2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
