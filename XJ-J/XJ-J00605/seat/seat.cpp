#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    if(a!=b){
        return a>b;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[15][15];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]>a[1][1]){
                sum++;
            }
        }
    }
    for(int i=1;i<=1;i++){
        for(int j=1;j<=1;j++){
            if(n==2){
                if(sum==1){
                cout<<i<<' '<<j+1;
            }
            if(sum==2){
                cout<<i+1<<' '<<j++1;
            }
            if(sum==3){
                cout<<i<<' '<<j+1;
            }
            }
        }
    }
    return 0;
}
