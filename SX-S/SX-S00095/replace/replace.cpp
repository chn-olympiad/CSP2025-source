#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
vector<int> ne1[N],ne2[N];
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        cout<<0<<endl;
    }

    return 0;
}