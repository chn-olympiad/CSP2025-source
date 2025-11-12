#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uli=unsigned long long int;
ifstream fin("club.in");
ofstream fout("club.out");
int main(void){
  ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
  size_t T;fin>>T;
  while (T--){
    size_t n;fin>>n;
    vector<array<ui,3>> a(n);
    array<vector<size_t>,3> d{{}};
    for (size_t i=0;i<n;++i){
      fin>>a[i][0]>>a[i][1]>>a[i][2];
      d[max_element(a[i].begin(),a[i].end())-a[i].begin()]
        .emplace_back(i);
    }
    for (size_t t=0;t<3;++t) if (d[t].size()>n/2){
      auto calc=[&](size_t x){
        ui s=0;
        for (size_t i=0;i<3;++i) if (i!=t) s=max(s,a[x][i]);
        return a[x][t]-s;
      };
      sort(d[t].begin(),d[t].end(),[&](size_t x,size_t y){
        return calc(x)>calc(y);
      });
      while (d[t].size()>n/2){
        size_t i=d[t].back();d[t].pop_back();
        size_t s=t==0?1:0;
        for (size_t j=0;j<3;++j) if (j!=t&&a[i][s]<a[i][j]) s=j;
        d[s].emplace_back(i);
      }
    }
    uli ans=0;
    for (size_t t=0;t<3;++t) for (auto i:d[t]) ans+=a[i][t];
    fout<<ans<<'\n';
  }
}

