#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans,i;
void choose(int num,int sum,int step)
{
    if(step==i)
    {
        if(num>=2&&sum>a[i])
        {
            ans++;
        }
        return;
    }
    choose(num,sum,step+1);
    choose(num+1,sum+a[step],step+1);
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=3;i<=n;i++)
    {
        choose(0,0,1);
    }
    cout<<ans;
    return 0;
}
