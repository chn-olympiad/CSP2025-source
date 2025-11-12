#include <iostream>
#include <algorithm>

using std::cin;
using std::sort;
using std::cout;

int n,k,ck,ans;
int a[500010],ca[500010];
int b[20],c[20],cnt;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    ck=k;
    cnt=0;
    while(ck)
    {
        c[cnt++]=ck%2;
        ck>>=1;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        ca[i]=a[i];
    }
    int lst=0;
    for(int i=1; i<=n; i++)
    {
        cnt=0;
        while(ca[i])
        {
            b[cnt++]+=ca[i]%2;
            ca[i]>>=1;
        }
        bool flag=true;
        for(int j=0; j<20; j++)
        {
            if(c[j]>b[j])
            {
                flag=false;
                break;
            }
        }
        if(!flag)continue;
        int f=0;
        for(int j=i; j>lst; j--)
        {
            f=f^a[j];
            if(f==k)lst=i,ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
