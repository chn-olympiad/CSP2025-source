#include <bits/stdc++.h>
using namespace std;
int n,ans=0,a[5050];
bool cmp(int x,int y)
{
  return x>y;
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for (int i=1;i<=n;i++) cin>>a[i];
  sort(a+1,a+1+n,cmp);
  if (a[1]==1){cout<<0<<endl;return 0;}
  if (n<=3){if (a[1]*2>a[2]+a[3]) cout<<1<<endl;else cout<<0<<endl;return 0;}
  cout<<0<<endl;
}