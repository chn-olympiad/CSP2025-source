#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
char a[maxn];
int s[maxn];
int cnt;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",a+1);
    int n=strlen(a+1);
    for(int i=1;i<=n;++i)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            s[++cnt]=(a[i]-'0');
           // printf("%lld ",s[s[0]]);
        }
    }
    sort(s+1,s+1+cnt);
    for(int i=cnt;i>=1;--i)
    {
        printf("%lld",s[i]);
    }
    //printf("\n");
    return 0;
}
