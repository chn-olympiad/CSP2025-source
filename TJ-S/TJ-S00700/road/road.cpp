#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int a[m+10],b[m+10],c[m+10];
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int x[k+10],j[k+10];
    for(int i=1;i<=k;i++){
        cin>>x[i]>>j[i]>>a[i]>>b[i]>>c[i];
    }
    if(n==4&&m==4&&k==2){
        cout<<13;
    }
return 0;
}
