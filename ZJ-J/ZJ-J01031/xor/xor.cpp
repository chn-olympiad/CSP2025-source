#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500001],sum[500001];
int solve1()
{
    vector<pair<int,int> >x;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            if((sum[i] xor sum[j-1])==k)
            {
                x.push_back({i,j});
            }
        }
    }
    sort(x.begin(),x.end());
    int ans=0,pre=0;
    for(auto i:x)
    {
        if(i.second>pre)
        {
            ans++;
            pre=i.first;
        }
    }
    return ans;
}
int solve2()
{
    bitset <1000001> x=0;
    int ans=0;
    x[k]=1;
    for(int i = 1;i <= n;i++)
    {
        if(x[sum[i]])
        {
            ans++;
            x=0;
            x[sum[i] xor k]=1;
        }
        x[sum[i] xor k]=1;
    }
    return ans;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1] xor a[i];
    }
    if(n<=1e4)
    {
        cout << solve1();
    }
    else
    {
        cout << solve2();
    }
}