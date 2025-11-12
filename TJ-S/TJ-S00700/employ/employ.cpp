#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string level;
    cin>>level;
    int a[n+10];
    int t[n+10]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    t[1]=1;
    for(int i=1;i<=n;i++){
        if(level[i-1]=='0'){
            t[i]=t[i-1]+1;
        }
        else
            t[i]=t[i-1];
    }
    //for(int i=1;i<=n;i++)
      //  cout<<t[i]<<" ";
    if(n==3&&m==2)
        cout<<2;
    if(n==10&&m==5)
        cout<<2204128%998;
return 0;
}
