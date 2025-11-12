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
ll rand_lr(ll l,ll r){
    return rand()%(r-l+1)+l;
}
void solve()
{
    cout<<10000<<' '<<1000000<<' '<<10<<endl;
    forl(i,1,1e6)
        cout<<rand_lr(1,1e4)<<' '<<rand_lr(1,1e4)<<' '<<rand_lr(1,1e4)<<endl;
    forl(i,1,10)
    {
        cout<<rand_lr(1,1e4)<<' ';
        forl(j,1,1e4)
            cout<<rand_lr(1,1e4)<<' ';
        cout<<endl;
    }
}
int main()
{
    srand(time(0));
    // freopen(".in","r",stdin);
    freopen("road5.in","w",stdout);
    IOS;
    _t_=1;
    cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}