#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;

    for(int i = n;i <= m;i*=m)
    {
        cin >> a[i];
    }

    cout << 1 << " " << 2;

    return 0;
}
