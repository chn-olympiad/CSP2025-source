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
#define siz(x) (int)x.size()
const int N=4e5+3, M=5.4e6+3, K=2.8e6+3;
int n, m;
string a[N], b[N];

int calc(string a, string b, string c, string d){
  if(a.size()!=b.size()) return 0;
  int cnt=0;
  rep(i, 0, siz(a)-siz(c)){
    if(a.substr(i, siz(c))==c){
      string tmp=a;
      rep(j, 0, siz(c)-1) tmp[i+j]=d[j];
    if(tmp==b) ++cnt;
    }
  }
  return cnt;
}

signed main(){
  // freopen("replace.in", "r", stdin);
  // freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  rep(i, 1, n) cin>>a[i]>>b[i];
  rep(i, 1, m){
    string s, t;
    cin>>s>>t;
    int ans=0;
    rep(j, 1, n){
      ans+=calc(s, t, a[j], b[j]);
    } 
    cout<<ans<<'\n';
  }
}