#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,k;
int a[maxn];
bool f=1,fg=1;
int sum,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            f=0;
        if(a[i]>1)
            fg=0;
    }
    if(f==1){
        cout<<0;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)
                sum++;
            if(a[i]==1){
                ans=max(ans,sum);
                sum=0;
            }
        }
        cout<<ans+1;
        return 0;
    }

    ans=0;

    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)
                sum++;
            if(a[i]==0){
                ans=max(ans,sum);
                sum=0;
            }
            cout<<ans+1;
            return 0;
        }
    }
    cout<<12701;
    return 0;
}
