#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N],p[N],ans;
char s[N];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>(s+1);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        p[i]=i;
    }
    if(n<=10)
    {
        do
        {
            int tot=0;
            for(int i=1,cnt=0;i<=n;i++)
            {
                if(cnt>=c[p[i]]||s[i]=='0') cnt++;
                else tot++;
            }
            if(tot>=m) ans++;
        }while(next_permutation(p+1,p+n+1));
        cout<<ans;
    }
    else cout<<0;
}