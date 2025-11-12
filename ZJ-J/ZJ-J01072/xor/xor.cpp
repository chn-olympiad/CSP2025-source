#include<bits/stdc++.h>
using namespace std;
//又是 DP？（前缀和优化）爽死了 qwq
//都不多测？！
//20 行，诗人
int n,k,a[500010],sum[500010],l[2000010],f[500010];
int main()
{freopen("xor.in","r",stdin);
 freopen("xor.out","w",stdout);
 cin>>n>>k;
 for(int i=1;i<=2000000;i++) l[i]=-1;
 for(int i=1;i<=n;i++)
 {cin>>a[i];
  sum[i]=(sum[i-1]^a[i]);
  if(l[sum[i]^k]!=-1)
  f[i]=f[l[sum[i]^k]]+1;
  f[i]=max(f[i],f[i-1]);
  l[sum[i]]=i;
 }
 cout<<f[n];
 return 0;
}
