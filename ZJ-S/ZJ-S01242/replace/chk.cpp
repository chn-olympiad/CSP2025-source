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
ll len=27578;
string s[1000010];
void solve()
{
    forl(i,1,len)
        cin>>s[i];
    forl(i,1,len)
    {
        string S;
        cin>>S;
        if(S!=s[i])
        {
            cout<<"WA"<<i<<endl;
            return ;
        }
    }
    cout<<"AC\n";
}
int main()
{
    freopen("replace.out","r",stdin);
    freopen("ck.out","w",stdout);
    IOS;
    _t_=1;
    // cin>>_t_;
    while(_t_--)
        solve();
    return 0;
}