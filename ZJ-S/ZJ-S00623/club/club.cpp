#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll T,n,ans,p[N],ct1,ct2,ct3;
struct P{
    ll a,b,c,val;
    bool operator<(const P& B){return val<B.val;}
}a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;ans=ct1=ct2=ct3=0;
        for(int i=1;i<=n;i++)
            cin>>a[i].a>>a[i].b>>a[i].c;

        for(int i=1;i<=n;i++) p[i]=a[i].a;
        sort(p+1,p+n+1,less<ll>());
        for(int i=1;i<=n/2;i++) ct1+=p[i];
        for(int i=1;i<=n;i++) p[i]=a[i].b;
        sort(p+1,p+n+1,less<ll>());
        for(int i=1;i<=n/2;i++) ct2+=p[i];
        for(int i=1;i<=n;i++) p[i]=a[i].c;
        sort(p+1,p+n+1,less<ll>());
        for(int i=1;i<=n/2;i++) ct3+=p[i];

        for(int i=1;i<=n;i++){
            if(ct2>max(ct1,ct3)) swap(a[i].a,a[i].b);
            else if(ct3>max(ct1,ct2)) swap(a[i].a,a[i].c);
        }
        for(int i=1;i<=n;i++) ans+=a[i].a,a[i].val=min(a[i].a-a[i].b,a[i].a-a[i].c);
        sort(a+1,a+n+1);
        for(int i=1;i<=n/2;i++){
            ans-=a[i].val;
            if(a[i].a-a[i].b==a[i].val) a[i].val=a[i].b-a[i].c;
            else a[i].val=a[i].c-a[i].b;
        }
        for(int i=n/2+1;i<=n;i++)
            if(a[i].val<0) ans-=a[i].val;
            else break;
        cout<<ans<<"\n";
    }
    return 0;
}