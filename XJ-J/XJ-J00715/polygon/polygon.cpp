#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 5010;
const int MOD = 998244353;
int n;

int a[N];
int s[N];
int ans;
int C(int a,int b)//C  b/a
{
    int idx=1;
    for(int i=a;i>b;i--)
        idx=idx*i;
    return idx;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];

    for(int i=3;i<=n;i++)
    {

        for(int j=1;j<=i-2;j++) //pipei 
        {

            //qujian[]
            for(int k=2;j+k<i;k++)
            {
                int u=s[j+k-1]-s[j-1];
                if(u>a[i])
                {
                    ans+=C(i-j,k);
                }
            }
        }
    }

    if(n==3)
    {
        if(s[n]<a[n])
            ans = 1;
    }

    
    cout << ans;
    return 0;
}