#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int ptc=5e2+10;
const int mod=998244353;
int ar[ptc];
char sd[ptc];
int epx[ptc];
int fac(int x)
{
    long long r=1;
    for(int i=2;i<=x;i++)r=r*i%mod;
    return r;
}
void nms(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(sd[i]=='0'||epx[i]==0)
        {
            puts("0");
            return;
        }
    }
    printf("%d",fac(n));
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",sd+1);
    for(int i=1;i<=n;i++)scanf("%d",epx+i);
    if(n==m)
    {
        nms(n);
        return 0;
    }
    for(int i=1;i<=n;i++)ar[i]=i;
    int ans=0;
    do
    {
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(sd[i]=='0'||epx[ar[i]]<=c)c++;
        }
        if(c<=n-m)ans++;
    }while(next_permutation(ar+1,ar+n+1));
    printf("%d",ans);
    return 0;
}
