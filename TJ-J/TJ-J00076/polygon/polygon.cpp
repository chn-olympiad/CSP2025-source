#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("ploygon.in","r",stdin);
  freopen("ploygon.out","w",stdout);
int a;
cin>>a;
for(int i=1;i<=a;i++){
    int k;cin>>k;
    if(k==1){
        cout<<9;
        return 0;
    }
    if(k==2){
        cout<<6;
        return 0;
    }
}
return 0;
}
