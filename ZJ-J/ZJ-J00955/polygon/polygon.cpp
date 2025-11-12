#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n,a[5005],ans,m,k,p;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=3;i<=n;i++)
    {
        k=1;
        p=i;
        while(p--)
        {
            m+=a[k];
            k++;
        }
        if(m>2*a[k])
            ans+=n-k+1;
    }
    cout<<ans%998244353<<endl;
    return 0;
}
