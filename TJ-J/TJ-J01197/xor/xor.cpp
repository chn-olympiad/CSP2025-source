#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,mx=0;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
