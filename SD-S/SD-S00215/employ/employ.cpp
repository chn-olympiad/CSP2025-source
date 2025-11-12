#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uli=unsigned long long int;
ifstream fin("employ.in");
ofstream fout("employ.out");
int main(void){
  ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
  size_t n,m;fin>>n>>m;
  vector<bool> a(n);
  for (auto i:a){
    char c;fin>>c;
    i=c=='1';
  }
  vector<ui> d(n);
  for (ui& i:d) fin>>i;
  if (m==n){
    if (count(a.begin(),a.end(),false)>0||count(d.begin(),d.end(),0)>0){
      fout<<"0";
      return 0;
    }
    uli ans=1;
    for (ui i=1;i<=n;++i) ans=(ans*i)%998244353;
    fout<<ans;
    return 0;
  }
  vector<vector<uli>> f(1u<<n,vector<uli>(n+1));
  f[0][0]=1;
  for (ui b=0;b<(1u<<n);++b) for (size_t i=0;i<n;++i){
    for (size_t j=0;j<n;++j) if (!((b>>j)&1u))
      f[b|(1u<<j)][i+!(a[__builtin_popcount(b)]&&i<d[j])]+=f[b][i];
  }
  uli ans=0;
  for (size_t i=0;i+m<=n;++i) ans+=f.back()[i];
  fout<<ans%998244353;
}

