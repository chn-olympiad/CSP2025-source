#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); ++i)
#define per(i, j, k) for(int i=(j); i>=(k); --i)
using namespace std;
namespace DEBUG{
  template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
  template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d || *s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<",";
    _debug(s+1, nxt...);
  } 
  template<class T> ostream& operator<<(ostream &c, vector<T> v){
    c<<'[';
    for(auto x:v) c<<x<<", ";
    c<<']';
    return c;
  }
  #define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
} using namespace DEBUG;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
int ri(int l, int r){return rnd()%(r-l+1)+l;}
int n, m, k, w;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  n=2e5, m=2e5;
  cout<<n<<' '<<m<<'\n';
  rep(i, 1, n+m){
    k=ri(1, ri(1, ri(1, 100)));
    if(i>n) ++k;
    string a, b;
    do{
      a.resize(k), b.resize(k);
      rep(j, 1, k) a[j-1]=ri('a', 'b'), b[j-1]=ri('a', 'b');
    } while(a==b);
    cout<<a<<' '<<b<<'\n';
  }
}