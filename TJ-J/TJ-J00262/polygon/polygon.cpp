#include<bits/stdc++.h>
using namespace std;
int n,a[111],sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n,greater<int>());
    if(sum>a[n-1]*2)
        cout<<'1';
    else
        cout<<'0';
    return 0;
}
