#include <iostream>
using namespace std;
int n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if (n==3)
    {
        int b=max(max(a[1],a[2]),max(a[2],a[3]))
        if (a[1]+a[2]+a[3]>2*b)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        return 0;
    }
    int s=0;
    for (int j=1;i<=n;j++)
    {
        for (int k=j+1;k<=n;k++)
        {
            for (int p=k+1;p<=n;p++)
            {
                int b=max(max(a[j],a[k]),max(a[k],a[p])
                if (a[j]+a[k]+a[p]>2*b)
                {
                    s++;
                }
            }
        }
    }
    for (int j=1;i<=n;j++)
    {
        for (int k=j+1;k<=n;k++)
        {
            for (int p=k+1;p<=n;p++)
            {
                for (int i=p+1;i<=n;i++)
                {
                    int b=max(max(a[j],a[k]),max(a[p],a[i]),max(max(a[j],a[p]),max(a[k],a[i])),max(max(a[j],a[i]),max(a[k],a[i]),max(max(a[j],a[p]),max(a[k],a[i]))))
                    if (a[j]+a[k]+a[p]+a[i]>2*b)
                    {
                        s++;
                    }
                }
            }
        }
    }
    cout <<s;
    return 0
}
