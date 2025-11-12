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
string s;
ll a[100];
void solve()
{
    cin>>s;
    for(auto i:s)
        if(i>='0' && i<='9')
            a[i-'0']++;
    forr(i,9,0)
        while(a[i]--)
            cout<<i;
    cout<<endl;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}