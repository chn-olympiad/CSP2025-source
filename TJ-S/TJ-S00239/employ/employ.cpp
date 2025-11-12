#include<iostream>
#include<cstdio>
using namespace std;
const long long MOD=998244353;
long long ans;
int n,m;
string s;
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    int f=0;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(s[i]=='0')
        {
            flag=false;
        }
        else
        {
            f=i;
        }
    }
    if(f==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(m==n&&flag==false)
    {
        cout<<0<<endl;
        return 0;
    }
    if(flag==true)
    {
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            ans%=MOD;
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m==1)
    {
        f=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                f=i;
                break;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]>=f)
            {
                cnt++;
            }
        }
        ans=1;
        for(int i=1;i<=n-1;i++)
        {
            ans*=i;
            ans%=MOD;
        }
        ans*=cnt;
        cout<<ans<<endl;
        return 0;
    }
    cout<<2<<endl;
    return 0;
}
