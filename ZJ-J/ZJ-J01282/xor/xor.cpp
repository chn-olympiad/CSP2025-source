#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010];
int flag[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int num=0;
        for(int j=i;j>=1;j--){
            if(flag[j]) break;
            num^=a[j];
            if(num==k){
                ans++;
                flag[i]=1;
                break;
            }

        }
    }
    cout<<ans;
    return 0;
}
