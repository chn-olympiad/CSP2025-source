#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N=1e5+5,K=512;
int n,k,a[N],idx[N],ans;
void dfs(int x,int cnt)
{
 if(x==n+1)
 {
  int cnt_=1,xor_sum=a[1],f=0;
  for(int i=2;i<=cnt;i++)
  {
   if((idx[i]-idx[i-1]>1&&xor_sum==k)||xor_sum==k)
    cnt_++,xor_sum=0;
   xor_sum=xor_sum^a[i];
  }
  if(!f)
   ans=max(ans,cnt_);
 }
 if(x>n)
  return;
 idx[cnt+1]=x;
 dfs(x+1,cnt+1);
 idx[cnt+1]=0;
 dfs(x+1,cnt);
}
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	dfs(1,0);
    cout<<ans;
	return 0;
}
