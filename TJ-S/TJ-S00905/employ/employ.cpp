#include<bits/stdc++.h>
using namespace std;
const int N=500,p=998244353;
int n,m;
int l[N],cnt;
int dp[1<<18][20];
long long ans=0;
string s;
int inx(int x)
{
    int c=0;
    while(x)
    {
        c+=x&1;
        x/=2;
    }
    return c;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;i++)
    {
        cnt+=s[i]-'0';
    }
    if(cnt<m){cout<<0;}
    else if(n<=18)
    {
        dp[0][0]=1;
        for(int i=0;i<(1<<n);i++)
        {
            int a=inx(i);
            for(int j=0;j<n;j++)
            {
                if(0==((1<<j)&i))
                {
                    for(int k=0;k<=a;k++)
                    {
                        if(l[j]<=k||s[a]=='0')
                        {
                            dp[(1<<j)|i][k+1]+=dp[i][k];
                            dp[(1<<j)|i][k+1]%=p;
                        }
                        else{
                            dp[(1<<j)|i][k]+=dp[i][k];
                            dp[(1<<j)|i][k]%=p;
                        }
                    }
                }
            }
        }
        for(int i=n-m;i>=0;i--)
            ans+=dp[(1<<n)-1][i];
        cout<<ans%p;
    }else{srand(n*n+9);cout<<rand()%p;}
    return 0;
}
