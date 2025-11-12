#include <bits/stdc++.h>
using namespace std;
int n,m,a[205];
bool cmp(int x,int y)
{
  return x>y;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  for (int i=1;i<=n*m;i++) cin>>a[i];
  int r=a[1],w=1;
  sort(a+1,a+1+n*m,cmp);
  for (int i=1;i<=m;i++)
  {
  	for (int j=1;j<=n;j++){if (r==a[w]){cout<<i<<" "<<j<<endl;return 0;}w++;}
  	i++;
  	for (int j=n;j>=1;j--){if (r==a[w]){cout<<i<<" "<<j<<endl;return 0;}w++;}
  }
  return 0;
}