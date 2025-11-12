#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forl(i,a,b) for(re ll (i)=(a);(i)<=(b);(i)++)
#define forr(i,a,b) for(re ll (i)=(a);(i)>=(b);(i)--)
#define forll(i,a,b,c) for(re ll (i)=(a);(i)<=(b);(i)+=(c))
#define forrr(i,a,b,c) for(re ll (i)=(a);(i)>=(b);(i)-=(c))
#define pii pair<ll,ll>
#define pb push_back
ll _t_;
ll n,m,k,l;
ll b[110][110];
ll a[100010];
bool cmp(ll x,ll y){
    return x>y;
}
void solve()
{
    cin>>m>>n;
    forl(i,1,n*m)
        cin>>a[i];
    l=a[1];
    sort(a+1,a+1+n*m,cmp);
    forl(i,1,n)
    {
        if(i&1)
            forl(j,1,m)
                b[i][j]=a[++k];
        else
            forr(j,m,1)
                b[i][j]=a[++k];
    }
    // forl(i,1,n)
    // {
        // forl(j,1,m)
            // cout<<b[i][j]<<' ';
        // cout<<endl;
    // }
    forl(i,1,n)
        forl(j,1,m)
            if(b[i][j]==l)
            {
                cout<<i<<' '<<j<<endl;
                return ;
            }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}