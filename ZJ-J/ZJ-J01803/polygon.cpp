#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define VE vector
LL n,ma;VE<LL> ar;
LL a(LL x,LL y,VE<LL>jc){
    return jc[y-1]/jc[max(0LL,y-x-1)];
}
void wo1(){
    VE<LL>jc(n);jc[0]=1;LL ans=0;
    for(LL i=1;i<n;i++)jc[i]=jc[i-1]*(i+1);
    for(LL i=4;i<=n;i++){ans+=(a(i,n,jc)/a(i,i,jc));}
    cout<<ans;
}
void d(){
    for()
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",sdout);
    cin>>n;ar.resize(n);
    for(LL i=0;i<n;i++){cin>>ar[i];ma=max(ma,ar[i]);}
    if(ar[0]+ar[1]+ar[2]>ma*2)cout<<1;
    else cout<<0;
}
