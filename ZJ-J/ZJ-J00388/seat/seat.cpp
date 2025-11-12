#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105];
bool cmp (int x,int y)
{
	return x>y;
}
int main()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    int b=a[1];
    sort (a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]==b)
        {
            if (((i-1)/n+1)%2==0)
            {
                if (i%n==0)
                {
                    cout << (i-1)/n+1 << " " << n;
                }
                else
                {
                  cout << (i-1)/n+1 << " " << n-i%n+1;
                }
            }
            else if (((i-1)/n+1)%2==1)
            {
                cout << (i-1)/n+1 << " " << i%(2*n);
            }
        }
    }
    return 0;
}
