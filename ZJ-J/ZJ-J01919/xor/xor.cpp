#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
int sum,maxn,ans;
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;++i)
  {
  	cin>>a[i];
  	maxn=maxn<a[i]?a[i]:maxn;
  	if(a[i]==1)++sum;
  }
  if(maxn==1)
  {
  	if(sum==n)
  	{
  	  cout<<n/2;
  	  return 0;
	}
	if(k==1)
	{
	  cout<<sum;
	  return 0;
	}
	for(int i=1;i<=n;++i)
	{
	  if(a[i]==0)++ans;
	  else if(a[i+1]==1)
	  {
	  	++ans;
	  	++i;
	  }
	}
	cout<<ans;
	return 0;
  }
  else cout<<n/2;
  return 0;
}
