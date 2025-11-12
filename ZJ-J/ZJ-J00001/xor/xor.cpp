#include <bits/stdc++.h>
using namespace std;
int a[25],s[5000005],fin[5000005];
struct qujian
{
    int left,right;
} q[5000005];
int sxor(int l,int r)
{
    for (int i = l;i <= r;i++)
    {
        int x = s[i],cnt = 1;
        while (x)
        {
            if (x % 2 == 1)
                a[cnt]++;
            cnt++;
            x >>= 1;
        }
    }
    int quanzhong = 1,sum = 0;
    for (int i = 1;i <= 22;i++)
    {
        if (a[i] % 2 == 1)
            sum += quanzhong;
        quanzhong *= 2;
    }
    return sum;
}
bool cmp(qujian x1,qujian x2)
{
    return x1.left < x2.left;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        cin >> s[i];
    }
    int l = 1,r = 1,sum = 0;
    while (l < n)
    {
        while (sxor(l,r) != k)
        {
            r++;
            if (r > n)
            {
                l++;
                r = l;
            }
            if (l > n)
                break;
        }
        q[sum].left = l;
        q[sum].right = r;
        sum++;
        l++;
        r = l;
    }
    sort(q,q + sum,cmp);
    int ans = 0,cnt = 0;
    for (int i = 0;i < sum;i++)
    {
        if (cnt < q[i].left)
        {
            cnt = q[i].right;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
