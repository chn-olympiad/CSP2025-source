#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> b[3];
int a[100001][3];

int js(int x)
{
    int ax,bx;
    ax = max(a[x][0],max(a[x][1],a[x][2]));
    if(a[x][0] == ax)
    {
        bx = max(a[x][1],a[x][2]);
    }
    else if(a[x][1] == ax)
    {
        bx = max(a[x][0],a[x][2]);
    }
    else
    {
        bx = max(a[x][0],a[x][1]);
    }
    return ax-bx;
}

bool cmp(int x,int y)
{
    return js(x) < js(y);
}

void lll()
{
    int n;
    scanf("%lld",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
    }
    int cnt1,cnt2,cnt3;
    cnt1 = cnt2 = cnt3 = 0;
    int ans = 0;
    b[0].clear();
    b[1].clear();
    b[2].clear();
    for(int i = 1;i <= n;i++)
    {
        int mx = max(a[i][0],max(a[i][1],a[i][2]));
        ans += mx;
        if(a[i][0] == mx)
        {
            cnt1++;
            b[0].push_back(i);
        }
        else if(a[i][1] == mx)
        {
            cnt2++;
            b[1].push_back(i);
        }
        else
        {
            cnt3++;
            b[2].push_back(i);
        }
    }
    if(cnt1 > n/2)
    {
        sort(b[0].begin(),b[0].end(),cmp);
        for(int i = 0;i < cnt1-n/2;i++)
        {
            ans -= js(b[0][i]);
        }
    }
    else if(cnt2 > n/2)
    {
        sort(b[1].begin(),b[1].end(),cmp);
        for(int i = 0;i < cnt2-n/2;i++)
        {
            ans -= js(b[1][i]);
        }
    }
    else if(cnt3 > n/2)
    {
        sort(b[2].begin(),b[2].end(),cmp);
        for(int i = 0;i < cnt3-n/2;i++)
        {
            ans -= js(b[2][i]);
        }
    }
    printf("%lld\n",ans);
}

#undef int
int main()
{
#define int long long

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        lll();
    }
    return 0;
}
