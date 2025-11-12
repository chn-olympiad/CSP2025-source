#include <bits/stdc++.h>
using namespace std;
long long n,k,a[50010],cnt,ans;
bool is=false,s[50010];
int yh(int x,int y)
{
    return (x|y)-(x&y);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    memset(s,false,sizeof(s));
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=n;i>=1;i--)
    {
        for (int j=i;j<=n;j++)
        {
            cnt=0;
            is=false;
            for (int l=i;l<=j;l++)
            {
                cnt=yh(cnt,a[l]);
                if (s[l])
                {
                    is=true;
                    break;
                }
            }
            if (is)
            {
                continue;
            }
            if (cnt==k)
            {
                for (int w=i;w<=j;w++)
                {
                    s[w]=true;
                }
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
