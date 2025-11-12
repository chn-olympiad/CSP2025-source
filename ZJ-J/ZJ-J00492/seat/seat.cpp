#include<bits/stdc++.h>
#define ll long long
#define ac ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
ll n,m,a[105],fs,pm,ans;
ll finds(ll key)
{
  ll l=1,r=n*m,mid=(l+r)>>1;
  while(1)
  {
  	mid=(l+r)>>1;
  	if(a[mid]==key) break;
	else if(a[mid]<key) l=mid;
  	else r=mid;
  }
  return mid;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  ac;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
  {
  	for(ll j=1;j<=m;j++)
  	{
  	  cin>>a[(i-1)*n+j];
	}
  }
  fs=a[1];
  sort(a+1,a+n*m+1);
  pm=n*m-finds(fs)+1;
  ans=((pm-1)/n+1);
  cout<<ans<<" ";
  if(ans%2==1)
  {
  	cout<<pm-((ans-1)*n);
  }
  else
  {
  	cout<<n-(pm-((ans-1)*n))+1;
  }
  return 0;
}
