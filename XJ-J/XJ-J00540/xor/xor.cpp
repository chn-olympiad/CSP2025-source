#include<bits/stdc++.h>
using namespace std;
long long int a[500005]={0},b[500005]={0},i,j,n,k,ans=0,l=0;
int main()
{
 freopen("xor.in","r",stdin);
 freopen("xor.out","w",stdout);
 cin>>n>>k;
 for(i=1;i<=n;i++)
 {
  cin>>a[i];
  b[i]=b[i-1]^a[i];
 }
 for(i=1;i<=n;i++)
 for(j=l;j<i;j++)
 if((b[i]^b[j])==k)
 {
  l=i;
  ans++;
  break;
 }
 cout<<ans;
 return 0;
}
