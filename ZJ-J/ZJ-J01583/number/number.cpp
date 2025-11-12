#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxl=1e6+10;
int flag[maxl];
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int num[maxl];

    int cnt=0;
    for(auto i:s)
    {
        if(i>='0'&&i<='9')
        {
            cnt++;
            num[cnt]=i-'0';
        }
    }
    int m=cnt;
    int q;
    int ans=0;
    while(cnt>0)
    {
        int big=-1;
        q=0;
        for(int j=1;j<=m;++j)
        {
            if(!flag[j])
            {
                if(num[j]>big)
                {
                   big=max(big,num[j]);
                   q=j;
                }
            }
        }
        ans=ans*10+big;
        flag[q]=1;
        cnt--;
    }
    printf("%lld\n",ans);
    return 0;
}
