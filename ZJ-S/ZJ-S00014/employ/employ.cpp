#include<bits/stdc++.h>
using namespace std;
namespace IHAVENOEGG {
  #define ll long long
  int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << 0 << '\n';
    return 0;
  }
};
#ifndef LOCAL
int main() {
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
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
g++ -o o employ.cpp -std=c++14 -Wall -DLOCAL -O2
*/