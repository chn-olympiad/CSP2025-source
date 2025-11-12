#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[n+1],a1[n+1],n1,n2,k,j;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    k=a[1];
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        a1[i]=i;
        if(a[i]==k) j=a1[i];
    }
    if(j%n==0)
    {
        n1=j/n;
    }
    else
    {
        n1=j+1;
    }
    if(j%n==0)
    {
        n2=n;
    }
    else
    {
        n2=j%n+1;
    }
    cout<<n1<<" "<<n2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
