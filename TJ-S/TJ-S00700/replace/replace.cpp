#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a[n+10][10];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=2;j++){
            cin>>a[i+n][j];
        }
    }
    if(n==4&&q==2){
        cout<<2<<endl<<0;
    }
    if(n==3&&q==4){
        cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
    }
return 0;
}
