#include <bits/stdc++.h>
using namespace std;
int a[1005];
int c[5005][5005];//i choose j
int mod=998244353;
string js(int x,int y)
{
    string s="";
    while (x>0)
    {
        char c=(x%2)+'0';
        s=c+s;
        x/=2;
    }
    while (s.size()<y) s='0'+s;
    return s;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if (maxx==1)
    {
        for(int i=0;i<=n+2;i++) c[i][0]=1;
        for(int i=1;i<=n+2;i++)
        {
            c[i][i]=1;
            for(int j=1;j<=i-1;j++)
            {
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
            }
        }
        int ans=0;
        for(int i=3;i<=n;i++)
        {
            ans=(ans+c[n][i])%mod;
        }
        cout<<ans;
    }
    else
    {
        int ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            string s=js(i,n);
            //cout<<s<<" ";
            int cnt=0,num=0,maxy=0;
            for(int i=0;i<n;i++)
            {
                if (s[i]=='1')
                {
                    cnt++;
                    num+=a[i+1];
                    maxy=max(maxy,a[i+1]);
                }
            }
            //cout<<maxy<<" "<<num<<" "<<cnt<<" "<<endl;
            if (cnt>=3 && num>2*maxy) ans++;
        }
        cout<<ans;
    }
    return 0;
}
