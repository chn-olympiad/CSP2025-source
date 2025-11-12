#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000],b[10000];
int ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        if(a[1]+a[2]+a[3]>2*a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=i+2;j<=n;j++){

        }
    }
    return 0;
}
