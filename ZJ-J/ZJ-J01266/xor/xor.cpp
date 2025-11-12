#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define INF 1061109567
int a[N],b[N],c[N];
int f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    memset(c,0x3f,sizeof c);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=a[i]^b[i-1];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((b[j]^b[i-1])==k){
                c[i]=j;
                break;
            }
        }
    }int ma=0;
    for(int i=1;i<=n;i++){
        if(c[i]!=INF){
            if(f[i]+1>f[c[i]]){
                for(int j=c[i]+1;j<=n+1;j++){
                    f[j]=max(f[j],f[i]+1);
                }
                ma=max(ma,f[c[i]+1]);
            }
        }
    }cout<<ma;
    return 0;
}
