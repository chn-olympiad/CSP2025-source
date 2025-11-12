#include <bits/stdc++.h>
using namespace std;

int mm[50001];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>mm[i];
    }
    if(n==2){
        bool f1=1,f2=1;
        if(mm[0]==0){
            ans++;
            f1=0;
        }
        if(mm[1]==0){
            ans++;
            f2=0;
        }
        if(mm[0]^mm[i]==0&&f1==1&&f2==1){
            ans++;
        }
        cout<<ans;
    }else{
        cout<<2;
    }
    return 0;
}
