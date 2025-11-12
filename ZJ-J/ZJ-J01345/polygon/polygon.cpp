#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[5010];
int b[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int c = 0;
    for (int i=1;i <= n;i++)
        cin >> a[i];
    if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[3] + a[2] > a[1])
        c++;
    cout << c << endl;
    return 0;
}

