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
#define int long long
const int N=1e5+3;
int n, a[N][3], sum, cnt[3], d[N][3];

void run(){
  //remember clear
  rep(i, 0, 2) cnt[i]=0;
  sum=0;
  cin>>n;
  rep(i, 1, n){
    cin>>a[i][0]>>a[i][1]>>a[i][2];
    d[i][0]=0, d[i][1]=1, d[i][2]=2;
    sort(d[i], d[i]+3, [&](int x, int y){return a[i][x]>a[i][y];});
    cnt[d[i][0]]++;
    sum+=a[i][d[i][0]];
  }
  rep(c, 0, 2) if(cnt[c]>n/2){
    int x=cnt[c]-n/2;
    vector<int> cost;
    rep(i, 1, n) if(d[i][0]==c){
      cost.emplace_back(a[i][d[i][0]]-a[i][d[i][1]]);
    }
    sort(cost.begin(), cost.end());
    rep(i, 0, x-1) sum-=cost[i];
  }
  cout<<sum<<'\n';
}

signed main(){
  // freopen("club.in", "r", stdin);
  // freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int t; cin>>t;
  while(t--) run();
}