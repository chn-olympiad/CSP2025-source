#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[120],r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1);
    int pos=lower_bound(a+1,a+n*m+1,r)-a;
    pos=n*m-pos+1;
    if((pos-1)/n%2==0) cout<<(pos-1)/n+1<<" "<<(pos-1)%n+1;
    else cout<<(pos-1)/n+1<<" "<<n-((pos-1)%n);
    return 0;
}
