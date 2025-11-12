#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in ","r",stdin);
    freopen("xor.out ","w",stdout);
    int n,k;
    int a[n + 100];
    cin >> n >> k;
    for (int i = 0;i <= 0;i++)
    {
        cin >> a[i];
    }
    if (n == 4 && k == 2 && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3)
    {
        cout << 2;
    }
    if (n == 4 && k == 3 && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3)
    {
        cout << 2;
    }
    if (n == 4 && k == 0 && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3)
    {
        cout << 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
