#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[3002];
    cin>>a;
    int b[10]={};
    for(int i=0;i<sizeof(a);i++){
        if(a[i]>='0' && a[i]<='9'){
            b[a[i]-'0']++;
        }
    }
    for(int i=9;i>0;i--){
        while(b[i]>0){
            cout<<i;
            b[i]--;
        }
    }
    return 0;
}
