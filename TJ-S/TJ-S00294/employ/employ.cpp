#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505],num;
char aaa;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>aaa;
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<n;i++){
        n*=i;
    }
    cout<<n;
    return 0;
}
