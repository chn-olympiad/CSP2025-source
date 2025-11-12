#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    frepoen("xor.out","w",stdout);
    int n,k,a[500003]={};
    cin>>n>>k;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k) s++;
    }
    cout<<s;
    return 0;
}
