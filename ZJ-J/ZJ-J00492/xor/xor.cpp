#include<bits/stdc++.h>
#define ll long long
#define ac ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+10;
ll n,k,a[N],s,jy=1,ans;
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  ac;
  cin>>n>>k;
  for(ll i=1;i<=n;i++)
  {
  	cin>>s;
  	for(ll j=jy;j<=i;j++)
  	{
  	  a[j]=a[j] xor s;
  	  if(a[j]==k)
	  {
		ans++;
		jy=j+1;
		for(ll k=jy;k<=i;k++) a[k]=0;
		break;
	  }
	}
  }
  cout<<ans;
  return 0;
}
