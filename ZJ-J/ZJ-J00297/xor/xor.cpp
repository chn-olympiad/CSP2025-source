#include <bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,k,a[N],f[N],x,maxr=-INT_MAX,ans;
signed main()
{
  AKIOI;
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>a[i];
  f[0]=0;
  f[1]=a[1];
  for(int i=2;i<=n;i++)
  {
  	f[i]=(f[i-1] xor a[i]);
  }
  int ll=1;
  for(int i=1;i<=n;i++)
  {
  	for(int j=i;j>=max((long long)1,maxr+1);j--)
  	{
  	  if((f[i] xor f[j-1])==k)
  	  {
  	    maxr=i;
  	    ans++;
	  }
	}
  }
  cout<<ans;
  return 0;
}
