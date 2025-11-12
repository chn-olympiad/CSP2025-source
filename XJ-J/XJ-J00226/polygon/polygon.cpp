#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,a[5005]={},b[5005]={};
    cin>>n;
    m=n;
    while(n>0){
        n--
        cin>>a[n];
    }
    sort(a+1,a+m+1);
    for(int i=1;i<m;i++){
        b[i]=a[i-1]+b[i-1];
    }
    int ans=0;
    for(int i=3;i<=m;i++){
        for(int j=0;j<=m-i;j++){
            if(b[j+i]-b[i] > a[j+i-1]*2) ans++;
        }
    }
    cout<<ans;
    return 0;
}
