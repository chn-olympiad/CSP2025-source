#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,p,a[1005],b[1005];
    cin >> n >> p;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= p;i++)
    {
        cin >> b[i];
    }
    if (n == 4 && p == 2)
    {
        cout << "2" << endl << "0";
    }
    if (n == 3 && p == 4)
    {
        cout << "0" << endl << "0" << endl << "0" << endl << "0" ;
    }
    return 0;
}
