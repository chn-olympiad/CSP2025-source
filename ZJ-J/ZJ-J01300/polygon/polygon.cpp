#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+8;
const int MOD=998244353;
int n,cnt,mx,a[MAXN];
void f(vector<int>b){
    long long lhs=0,rhs=0;
    for(int idx:b)lhs+=1ll*a[idx],rhs=max(rhs,1ll*a[idx]);
    if(lhs>rhs*2)cnt=(cnt+1)%MOD;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    //max_ai<=1,24Pts
    if(mx==0)return cout<<0,0;
    if(mx==1){
        if(n==3)return cout<<1,0;
        if(n==4)return cout<<5,0;
        int ans=6,add=10;
        for(int i=5;i<=n;i++)
            ans=(ans+add)%MOD,add=(add*2)%MOD;
        return cout<<ans,0;
    }
    //n<=3,12Pts
    if(n<=3)
        if((a[1]+a[2]+a[3])>2*max({a[1],a[2],a[3]}))
            return cout<<1,0;
        else return cout<<0,0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
