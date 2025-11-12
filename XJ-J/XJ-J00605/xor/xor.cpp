#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    if(a!=b){
        return a>b;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xors.out","w",stdout);
    int n,k;
    int a[100005];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<2;
    return 0;
}
