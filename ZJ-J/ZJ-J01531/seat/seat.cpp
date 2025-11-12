#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110],c,u;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
        if(i==1) u=a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        c++;
        if(a[i]==u){
            break;
        }
    }
    ll v;
    if(c%n==0) v=c/n-1;
    else v=c/n;
    if(v%2==0){
        ll w=c-v*n;
        printf("%lld %lld",v+1,w);
    }
    else{
        ll w=c-v*n;
        printf("%lld %lld",v+1,n-w+1);
    }
    return 0;
}
