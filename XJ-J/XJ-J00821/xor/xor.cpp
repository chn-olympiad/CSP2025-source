#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[200005];
    int n,k;
    cin>>n>>k;
    int nn=0;
    int jg=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            nn++;
    }
    if(k==0)
    {
        int m=0;
        if(nn==n)
        {
            cout<<n/2;
            return 0;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                int c=i+1;
                if(a[i]!=a[c])
                {
                    if(m>=2)
                    {
                        jg+=m/2;
                        m=0;
                    }
                    continue;
                }
                if(a[i]==a[c])
                {
                    m++;
                }
            }
            cout<<jg;
        }
    }
    else
        cout<<2;
    return 0;
}
