#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in ","r",stdin);
    freopen("seat.out ","w",stdout);
    int n,m;
    int a[n * m + 100];
    cin >> n >> m;
    for (int i = 0; i <= n * m;i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j <= n * m - 1; j++)
    {
         if (a[i + 1] > a[i])
        {
            a[i] = a[i + 1];
        }
    }
    cout << a[n * m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
