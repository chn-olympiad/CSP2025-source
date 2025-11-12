#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1500000,M=500010;
long long a[M];
long long k;
long long s[M];
long long f[N];
bool st[N];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    int n;
    cin >>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        if(a[i]==k)
        {
            f[i]++;
            st[i]=1;
            continue;
        }

        int idx=a[i];

        for(int j=i-1;j>=1;j--)
        {
            if(st[j]==1)
                break;
            idx=idx^a[j];
            if(idx==k)
            {
                st[i]=1;
                f[i]++;
                break;
            }
            
        }
        
    }
    cout<<f[n];

    return 0;
}