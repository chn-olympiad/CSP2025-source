#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
string p;
long long int n,a[1000005],b;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> b;
    int m=1;
    for (int i=1;i<=6;i++)
    {
        a[i]=b%10;
        b/=10;
        if (b==0)
        {
            break;
        }
        m++;
    }
    sort (a+1,a+m+1);
    for (int i=m;i>=1;i--)
    {
        cout << a[i];
    }
    return 0;
}
