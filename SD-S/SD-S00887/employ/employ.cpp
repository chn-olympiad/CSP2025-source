#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
template<typename T>inline void read(T&x){
  x=0;bool f=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
  while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
  if(f)x=~x+1;
}
#define ll long long
const int N=20;
const ll mod=998244353;
ll f[1<<N][N];
int n,p[N],m;
char s[25];
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  read(n);read(m);
  scanf("%s",s+1);
  for(int i=1;i<=n;++i)read(p[i]);
  f[0][0]=1;
  for(int cur=0;cur<(1<<n);++cur)
    for(int x=0;x<=n;++x)if(f[cur][x])
      for(int i=1;i<=n;++i)
        if(!(cur&(1<<(i-1)))){
          int len=__builtin_popcount(cur);
            int ncur=cur|(1<<(i-1));
          if(s[len+1]=='0'||x>=p[i])f[ncur][x+1]=(f[ncur][x+1]+f[cur][x])%mod;
          else f[ncur][x]=(f[ncur][x]+f[cur][x])%mod;
        }
  ll res=0;
  int cur=(1<<n)-1;
  for(int x=0;x<=n;++x)if(f[cur][x])
    if(n-x>=m)res=(res+f[cur][x])%mod;
  printf("%lld",res);
  return 0;
}
