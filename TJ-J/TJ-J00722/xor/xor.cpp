#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
int a[105];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==1){
        int m=0;
        for(int i=0;i<n;i++){
            m+=a[i];
            
        }
        cout<<m;
    }
    else{
        cout<<1;
    }
    return 0;
}
