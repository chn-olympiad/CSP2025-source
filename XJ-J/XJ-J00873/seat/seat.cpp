#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[1000],e,ans;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    e=a[1];
    sort(a+1,a+n*m+1);
    int o=1;
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==e)
        {
            ans=o;
            break;
        }
        o++;
    }
    if(ans%n==0)
    {
        cout<<ans/n<<" "<<n;
    }
    else if((ans/n)%2==1)
    {
        cout<<ans/n+1<<" "<<n-(ans%n)+1;
    }
    else if((ans/n)%2==0)
    {
        cout<<ans/n+1<<" "<<ans%n;
    }
    return 0;
}
