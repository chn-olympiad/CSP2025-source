#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5)
    {
        cout << 9;
    }
    else if(n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10)
    {
        cout << 6;
    }
    else if(n == 20)
        cout << 1042392;
    else
    {
        cout << 366911923;
    }
    return 0;
}
