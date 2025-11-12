#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e6+10;
char a[maxn];
char b[maxn];
int n,q;
int ch[maxn][30];
int convert(char x)
{
    return x-'a';
}
void build(int l)
{
    for(int i=1;i<=l;++i)
    {
        int k1=convert(a[i]);
        int k2=convert(b[i]);
        int &to1=ch[i][k1];
        int &to2=ch[i][k2];
        if(!to1)
        {
            ++to1;
        }
        if(!to2)
        {
            ++to2;
        }
    }
}
int query(int st)
{
    int res;
    for(int i=st;a[i];++i)
    {
        int k1=convert(a[i]);
        int k2=convert(b[i]);
        int &to1=ch[i-st+1][k1];
        int &to2=ch[i-st+1][k2];
        if(!to1||!to2)
        {
            break;
        }
        else
        {
            ++res;
        }
    }
    return res;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",a+1);
        scanf("%s",b+1);
        int l=strlen(a+1);
        build(l);
    }
    for(int i=1;i<=q;++i)
    {
        scanf("%s",a+1);
        scanf("%s",b+1);
        int ans=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]==b[i])
            {
                ++cnt1;
            }
            else
            {
                break;
            }
        }
        for(int i=n;i>=1;--i)
        {
            if(a[i]==b[i])
            {
                ++cnt2;
            }
            else
            {
                break;
            }
        }
        for(int i=1;i<=cnt1;++i)
        {
            int k=query(i);
            if(k+i-1+cnt2>=strlen(a+1))
            {
                ++ans;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
