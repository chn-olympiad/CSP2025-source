#include <bits/stdc++.h>
using namespace std;
int s[105];
bool cmp(int x1,int x2)
{
    return x1 > x2;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> s[i];
    }
    int num = s[1];
    sort(s + 1,s + n * m + 1,cmp);
    int a = 1;
    for (int i = 1;i <= n * m;i++)
    {
        if (s[i] == num)
            break;
        a++;
    }
    int rest_num = a % (2 * n),lieshu = a / ((2 * n) + 1) * 2;
    if (rest_num / (n + 1) > 0)
    {
        cout << lieshu + 2 << " " << 2 * n - rest_num + 1;
    }
    else
    {
        cout << lieshu + 1 << " " << rest_num;
    }
    return 0;
}
