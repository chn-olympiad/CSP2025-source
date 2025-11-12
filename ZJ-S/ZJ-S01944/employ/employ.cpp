#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,ans;
int s[505],c[505],num[505];
string s1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool flag=0;
    cin>>s1;
    for(int i=0;i<n;i++)
    {
        s[i+1]=s1[i]-'0';
        if(s[i+1])flag=1;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        //cin>>c[i];
        num[i]=i;
    }
    if(n<=100)
    {
        do
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(cnt>=c[num[i]])cnt++;
                else if(s[i]==0)cnt++;
            }
            ans+=(n-cnt>=m);
            ans%=mod;
        }while(next_permutation(num+1,num+n+1));
        printf("%d",ans);
    }
    else printf("%d",0);
    return 0;
}
