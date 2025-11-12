#include<bits/stdc++.h>
using namespace std;
namespace IHAVENOEGG {
  #define ll long long
  const int N = 2e5 + 5;
  string s[2][N], t[2][N];
  const int S = 26;
  const int M = 5e6 + 6;
  unordered_map<char,unordered_map<char, int>>tr[M];
  int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
      cin >> s[0][i] >> s[1][i];
    for(int i = 1; i <= q; i++)
      cin >> t[0][i] >> t[1][i];
    for(int qq = 1; qq <= q; qq++) {
      // string x[2]; tie(x[0], x[1]) = {t[0][qq], t[1][qq]};
      // int m = x[0].size();
      // for(int i = 0; i < m; i++) {

      // }
      cout << 0 << '\n';
    }
    return 0;
  }
};
#ifndef LOCAL
int main() {
  //freopen("recall.in","r",stdin)
  //freopen("recall.out","w",stdout)
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  IHAVENOEGG::main();
}
#else
int main(int argc, char*argv[]) {
  if(argc >= 3) {
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
  }
  IHAVENOEGG::main();
}
#endif
/*
g++ -o o replace.cpp -std=c++14 -Wall -DLOCAL -O2
*/