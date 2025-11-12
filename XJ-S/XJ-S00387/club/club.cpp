#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    freopen('club.in','r','stdin');
    freopen('club.out','w','stdout');
    long long t,a[100005],b[100005],c[100005];
    cin>>t;
    long long ans[t+5]=0;
    long long n;
    cin>>n;
    while(t--)
    {
        long long x=0,y=0,z=0,x2=0,y2=0,z2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>b[i]&&a[i]>c[i])
            {
                x++;
                x2+=a[i];
            }
            if(b[i]>a[i]&&b[i]>c[i])
            {
                y++;
                y2+=b[i];
            }
            if(c[i]>a[i]&&c[i]>b[i])
            {
                z++;
                z2+=c[i];
            }

        }
        ans[t]=x2+y2+z2;
    }

    for(int i=t;i>=1;i--)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}

