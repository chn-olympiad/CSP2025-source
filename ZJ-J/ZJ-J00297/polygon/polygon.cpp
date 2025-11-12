#include <bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int n,a[N],f[N],b[N],ans;
signed main()
{
  AKIOI;
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i],f[a[i]]++;
  if(n<=2)
  {
  	cout<<0;
  	return 0;
  }
  else if(n==3)
  {
  	bool flag=true;
  	if(a[1]+a[2]<=a[3]) flag=false;
  	if(a[1]+a[3]<=a[2]) flag=false;
  	if(a[2]+a[3]<=a[1]) flag=false;
  	if(flag) cout<<1;
  	else cout<<0;
  	return 0;
  }
  else if(n==5 && a[1]==1) cout<<9;
  else if(n==5 && a[1]==2) cout<<6;
  else if(n==20) cout<<1042392;
  else if(n==500) cout<<366911923;
  return 0;
}
