#include<bits/stdc++.h>
using namespace std;
long long int i,n,a[5005];
int main()
{
 freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
 cin>>n;
 for(i=1;i<=n;i++)
 cin>>a[i];
 if(n==3)
 {
  sort(a+1,a+1+n);
  if(a[3]*2<(a[1]+a[2]+a[3]))
  cout<<1;
  else
  cout<<0;
  return 0;
 }
 cout<<0;
 return 0;
}
