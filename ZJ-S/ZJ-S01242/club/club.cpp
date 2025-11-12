#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define forl(i,a,b) for(re ll (i)=(a);(i)<=(b);(i)++)
#define forr(i,a,b) for(re ll (i)=(a);(i)>=(b);(i)--)
#define forll(i,a,b,c) for(re ll (i)=(a);(i)<=(b);(i)+=(c))
#define forrr(i,a,b,c) for(re ll (i)=(a);(i)>=(b);(i)-=(c))
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pii pair<ll,ll>
#define pb push_back
#define x first
#define y second
ll _t_;
ll n;
ll ans;
ll a[100010][5];
ll b[100010];
ll id[100010];
pii c[100010];
ll d[5];
bool cmp(ll x,ll y){
    return x>y;
}
bool pmc(pii x,pii y){
    return x.x>y.x;
}
void Solve(ll x)
{
    // if(x==4)
    // {
    //     forl(i,1,n)
    //     {
    //         if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
    //             id[i]=i;
    //     }
    // }
    ll S=0;
    forl(i,1,n)
        S+=a[i][x];
    forl(i,1,n)
    {
        ll ma=-1,id=0;
        forl(j,1,3)
            if(j!=x)
            {
                if(ma<a[i][j])
                    id=j;
                else if(ma==a[i][j])
                    id=0;
                ma=max(ma,a[i][j]);
            }
        c[i]={ma-a[i][x],id};
    }
    sort(c+1,c+1+n,pmc);
    d[1]=d[2]=d[3]=0;
    d[x]=n;
    forl(i,1,n)
    {
        S+=c[i].x;
        d[x]--,d[c[i].y]++;
        if(d[1]<=n/2 && d[2]<=n/2 && d[3]<=n/2)
            ans=max(ans,S);
    }
    // ans=max(ans,S);
}
void solve()
{
    ans=0;
    cin>>n;
    forl(i,1,n)
        forl(j,1,3)
            cin>>a[i][j];
    forl(i,1,3)
        Solve(i);
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    IOS;
    _t_=1;
    cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}