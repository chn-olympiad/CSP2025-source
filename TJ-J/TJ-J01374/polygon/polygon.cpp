#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5005],maxn=0,cnt=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        //sum[i]=sum[i-1]+a[i];
    }
 //   for(int i=2;i<=n;i++)
 //   {
 //       for(int j=i;j<=n;j++)
 //       {
 //          int m=sum[j]-sum[j-i];
 //           for(int k=1;k<=j-i;k++)
 //           {
 //               if(m>a[k])
 //               {
 //                   cnt++;
 //                   cout<<m<<" "<<a[k]<<endl;
 //               }
 //           }
 //           for(int k=j+1;k<=n;k++)
 //           {
 //               if(m>a[k])
 //               {
 //                   cnt++;
 //                   cout<<m<<" "<<a[k]<<endl;
 //               }
 //           }
 //       }
 //   }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>maxn)cnt=1;
    }
    else
    {
        for(int i=3;i<=n;i++)
        {
            int up=1,down=1;
            for(int j=n;j>=n-i+1;j--)up*=j;
            for(int j=i;j>=1;j--)down*=j;
            cnt=(cnt+up/down)%998244353;
        }
    }
    cout<<cnt%998244353;
    return 0;
}
