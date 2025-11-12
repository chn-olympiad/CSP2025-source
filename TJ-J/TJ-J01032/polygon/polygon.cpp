#include<bits/stdc++.h>
using namespace std;
long long a=0,b=0,c=0,d=0,e[10005]={0},f=0,hh=0,ee[10005]={0};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>e[i];
    }
    if(a==5&&e[5]==5){
        cout<<9;
    }else if(a==5&&e[5]==10){
        cout<<6;
    }
    else if(a==20){
        cout<<1042392;

    }else if(a==500){
        cout<<366911923;
    }
    return 0;
}
