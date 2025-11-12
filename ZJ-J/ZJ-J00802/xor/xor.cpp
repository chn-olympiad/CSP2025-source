#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,k;
int a[500005],la;
int sum[500005];
int ans=0;
int flag=1;
int lid[1500005];
signed main(){
    //freopen("xor6.in","r",stdin);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k>1) flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) flag=0;
        sum[i]=(sum[i-1]^a[i]);
    }
    if(flag){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                else{
                    if(a[i-1]==1){
                        a[i]=a[i-1]=0;
                        ans++;
                    }
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
        }
    }else{
        if(n<=8000){
            for(int i=1;i<=n;i++){
                int id=0;
                for(int j=1;j<=i;j++){
                    if((sum[i]^sum[j-1])==k){
                        id=j;
                    }
                }
                if(id>la){
                    //cout<<id<<' '<<i<<endl;
                    ans++;
                    la=i;
                }
            }
        }else{
            memset(lid,-1,sizeof(lid));
            for(int i=1;i<=n;i++){
                int id=lid[(sum[i]^k)];
                lid[sum[i]]=i;
                if(id==-1) continue;
                id++;
                if(id>la){
                    //cout<<id<<' '<<i<<endl;
                    ans++;
                    la=i;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
