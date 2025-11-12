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
ll pw(ll x){
    return 1ll<<x;
}
ll _t_;
ll n,m,k;
ll x,y,z;
ll id[1000020];
struct node{
    ll x,y,z;
}a[1000020],b[12][10020],d[10020];
bool vis[1000020];
ll c[12];
ll ans,S,sz;
bool cmp(node x,node y){
    return x.z<y.z;
}
ll find(ll x)
{
    if(id[x]==x)
        return x;
    return id[x]=find(id[x]);
}
void Solve(ll iii)
{
    ll lim=n-1;
    m=n-1;
    forl(i,1,m)
        a[i]=d[i];
    S=0;
    forl(i,0,9)
        if(iii&pw(i))
        {
            S+=c[i+1];
            lim++;
            forl(j,1,n)
                a[++m]=b[i+1][j];
        }
    sort(a+1,a+1+m,cmp);
    forl(i,1,n+k)
        id[i]=i;
    sz=0;
    forl(i,1,m)
    {
        ll x=a[i].x,y=a[i].y,z=a[i].z;
        // cerr<<x<<' '<<y<<' '<<z<<endl;
        ll fx=find(x),fy=find(y);
        if(fx==fy)
            continue;
        id[fx]=fy;
        S+=z;
        sz++;
        if(sz==lim || S>ans)
            break;
    }
    // cout<<lim<<endl;
    ans=min(ans,S);
}
void solve()
{
    S=0,ans=9e18;
    cin>>n>>m>>k;
    forl(i,1,m)
        cin>>x>>y>>z,
        a[i]={x,y,z};
    forl(i,1,k)
    {
        cin>>c[i];
        forl(j,1,n)
            cin>>b[i][j].z,
            b[i][j].x=n+i,b[i][j].y=j;
    }
    sort(a+1,a+1+m,cmp);
    forl(i,1,n)
        id[i]=i;
    sz=0;
    forl(i,1,m)
    {
        ll x=a[i].x,y=a[i].y,z=a[i].z;
        // cerr<<x<<' '<<y<<' '<<z<<endl;
        ll fx=find(x),fy=find(y);
        if(fx==fy)
            continue;
        vis[i]=1;
        id[fx]=fy;
        S+=z;
        sz++;
        if(sz==n-1)
            break;
    }
    // if(sz!=n-1)
    //     cerr<<sz<<endl<<"bug1...\n\n\n";
    ans=min(ans,S);
    // cout<<ans<<endl;
    sz=0;
    forl(i,1,m)
        if(vis[i])
            a[++sz]=a[i];
    m=n-1;
    forl(i,1,n-1)
        d[i]=a[i];
    // cout<<sz<<endl;
    forl(i,0,pw(k)-1)
        Solve(i);
    cout<<ans<<endl;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}