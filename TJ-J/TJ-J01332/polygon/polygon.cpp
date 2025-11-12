#include <bits/stdc++.h>
using namespace std;
int flg[5005],b[5005],ans;
int n,a[5005],sum,maxn;
void f(int j,int i,int num)
{
    if(j>num)
    {
        if(sum>b[num-1]*2)
        {
            ans++;
            ans%=998244353;
        }
    }
    else
    {
        for(;i<n;i++)
        {
            b[j-1]=a[i];
            sum+=a[i];
            f(j+1,i+1,num);
            sum-=a[i];
        }
    }
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        f(1,0,i);
    }
    cout<<ans<<endl;
    return 0;
}
