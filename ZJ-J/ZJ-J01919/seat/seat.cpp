#include<bits/stdc++.h>
using namespace std;
int n,m,a1,x,ans=1;
int r,c;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>n>>m>>a1;
  for(int i=1;i<n*m;++i)
  {
  	cin>>x;
  	ans+=(x>a1);
  }
  r=(ans+n-1)/n;
  c=((r&1)==1?ans-(r-1)*n:(m-(ans-(r-1)*n)+1));
  cout<<r<<' '<<c;
  return 0;
}
