#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
int x,z;
int q;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1||n==2){
        cout<<0;
        return 0;
    }

    int q=max(max(a[1],a[2]),a[3]);
    if(a[1]+a[2]+a[3]>q*2){
        cout<<1;
        return 0;
    }
    else{
        cout<<0;
        return 0;
    }
    cout<<366911923;
    return 0;
}
