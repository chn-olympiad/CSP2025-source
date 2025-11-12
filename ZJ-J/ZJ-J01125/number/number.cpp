#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<int>cnt(10);
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;--i)
    {
        while(cnt[i])
        {
            printf("%lld",i);
            --cnt[i];
        }
    }
    printf("\n");
    return 0;
}