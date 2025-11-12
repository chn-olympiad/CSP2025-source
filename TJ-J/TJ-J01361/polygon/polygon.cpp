#include <bits/stdc++.h>
using namespace std;

int a[6000];
int f[5050][5050];

const int MOD =998244353;

//10:35 start
//11:07 finished
//dp
//11:14 test finished
//qu zuo di san ti


int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int t=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t=(t*2)%MOD;
        f[i][0]=t;
    }
    f[0][0]=1;
    sort(a+1,a+n+1);
    int ans=0;
    int m=a[n];
    for(int j=1;j<=n-1;j++)
    {
        for(int k=1;k<=m+1;k++)
        {
            if(k>=a[j]) f[j][k]=(f[j-1][k]+f[j-1][k-a[j]])%MOD;
            else f[j][k]=(f[j-1][0]+f[j-1][k])%MOD;
            //printf("j:%d k:%d m:%d a[j]:%d f[j][k]:%d\n",j,k,m,a[j],f[j][k]);
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        ans=(ans+f[i][a[i+1]+1])%MOD;
        //("i:%d ans:%d\n",i,ans);
    }
        //ans=ans+f[i-1][m];
    printf("%d",ans);
}
//want to play florr & chameleon run
