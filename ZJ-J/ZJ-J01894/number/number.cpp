#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
char s[maxn];
int a[maxn];
int sta;
int ans=0;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s);
    for(int i=0; s[i]; ++i)
    {
        if(s[i]>='0' && s[i]<='9')
        {
              a[++sta]=s[i]-'0';
        }
    }
    sort(a+1,a+1+sta);
    for(int i=sta; i>=1; --i)
    {
        printf("%lld",a[i]);
    }
    printf("\n");

    return 0;
}