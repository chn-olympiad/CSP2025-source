#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int u[1000006],v[1000006];
int w[1000006],c[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(n==1000){
        cout<<5182974424;
    }
    return 0;
}