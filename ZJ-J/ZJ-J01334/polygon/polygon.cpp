#include<bits/stdc++.h>
using namespace std;
const int slen=5e3+100;
int a[slen];
int n,max1=0;
long long ans=0;
void dfs(long long h,int da,int id,int gs)
{
  if(id>n)
  {
  	if(h>da*2&&gs>=3)  {ans=(ans+1)%998244353;}
  	return;
  }
  dfs(h+a[id],max(da,a[id]),id+1,gs+1);
  dfs(h,da,id+1,gs);
  return;
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  memset(a,0,sizeof(0));
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    max1=max(max1,a[i]);
  }  
  dfs(0,0,0,0);
  cout<<(ans/2)%998244353;
  return 0;
}