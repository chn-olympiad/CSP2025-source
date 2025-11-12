#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int c[500];
namespace test_1
{
    int main(const int n)
    {
        long long ans=1;
        for (int i=2;i<=n;++i)
            ans=ans*i%mod;
        printf("%lld",(ans%mod+mod)%mod);
        return 0;
    }
}
namespace test_2
{
    bool check(const int n,const int m,const string&s,const vector<int>&q)
    {
        int cnt=0,sum=0;
        for (int i=0;i<n;++i)
        {
            if (s[i]=='1'&&cnt<c[q[i]])
                sum++;
            else
                cnt++;
        }
        return sum>=m;
    }
    int main(const int n,const int m,const string&s)
    {
        vector<int>q(n);
        for (int i=0;i<n;++i)
            q[i]=i;
        int ans=0;
        do
        {
            if (check(n,m,s,q))
            {
                ans++;
                if (ans>=mod)
                    ans=0;
            }
        }while (next_permutation(q.begin(),q.end()));
        printf("%d",ans);
        return 0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    bool flag=true;
    for (int i=0;i<n;++i)
    {
        scanf("%d",&c[i]);
        if (c[i]==n)
            flag=false;
    }
    for (const char i:s)
        if (i=='0')
            flag=false;
    if (flag)
        return test_1::main(n);
    else if (m==n)
    {
        int cnt=0,sum=0;
        for (int i=0;i<n;++i)
        {
            if (s[i]=='1'&&cnt<c[i])
                sum++;
            else
                cnt++;
        }
        if (sum)
            return test_1::main(n);
        else
            printf("0");
    }
    else if (m==1)
        return test_1::main(n);
    return test_2::main(n,m,s);
}