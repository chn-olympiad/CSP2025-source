#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0;
    int a[1005];
    cin >>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin >>a[i];
    }
    for (int i=0; i<=n; i++)
    {
        if ((a[i]+a[i+1])%2==0)
        {
            sum+=(a[i]+a[i+1])/2;
        }
        else
        {
            sum+=((a[i]+a[i+1]-1)/2)+0;
        }
    }
    cout <<sum%2+1;
    return 0;
}
