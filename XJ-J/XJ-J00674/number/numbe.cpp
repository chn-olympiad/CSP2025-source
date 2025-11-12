#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N];
int c[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;`
    for(int i=0;i<strlen(a);i++){
        if('0'<=a[i]&&a[i]<='9'){
            c[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=c[i];j++){
            cout<<i;
        }
    }
    return 0;
}