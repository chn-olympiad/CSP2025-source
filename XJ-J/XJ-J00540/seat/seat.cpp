#include<bits/stdc++.h>
using namespace std;
long long int i,n,m,a,l,s[105],x;
int main()
{
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 cin>>n>>m;
 for(i=1;i<=n*m;i++)
 cin>>s[i];
 x=s[1];
 sort(s+1,s+1+n*m,greater<long long int>());
 for(i=1;i<=n*m;i++)
 if(s[i]==x)
 a=i;
 l=ceil(a*1.0/n);
 if(l%2==0)
 {
  if(a%n!=0)
  cout<<l<<" "<<n-a%n+1;
  else
  cout<<l<<" "<<1;
 }
 else
 {
  if(a%n!=0)
  cout<<l<<" "<<a%n;
  else
  cout<<l<<" "<<n;
 }
 return 0;
}
