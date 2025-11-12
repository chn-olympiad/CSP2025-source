#include<bits/stdc++.h>
using namespace std;
int n,m,tot,a[110],x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    tot=n*m;
    for(int i=1;i<=tot;++i) cin>>a[i];
    x=a[1];
    sort(a+1,a+tot+1);
    int p=lower_bound(a+1,a+tot+1,x)-a;
    p=tot-p+1;
    int q=p/n,r=p%n;
    if(r==0){
        if(q&1) cout<<q<<" "<<n<<"\n";
        else cout<<q<<" "<<1<<"\n";
        return 0;
    }
    s0=q+1;
    if(q&1) cout<<q+1<<" "<<n-r+1<<"\n";
    else cout<<q+1<<" "<<r<<"\n";
    return 0;
}