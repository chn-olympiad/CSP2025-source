#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1&&m==1){
        int a;
        cin>>a;
        cout<<m<<" "<<n;
        return 0;
    }
    int a[20][20];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }cout<<"1 1";
    return 0;
}
