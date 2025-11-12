#include<bits/stdc++.h>
using namespace std;

const int MAXN=13;

int c[MAXN];

int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  s=" "+s;
  for(int i=1;i<=n;++i){
    cin>>c[i];
  }
  vector<int> p;
  for(int i=1;i<=n;++i){
    p.push_back(i);
  }
  int ans=0;
  do{
    int cnt=0;
    for(int i=0;i<p.size();++i){
      //i+1Ìì
      if(cnt>=c[p[i]]){
        ++cnt;
        continue;
      }
      if(s[i+1]=='0'){
        ++cnt;
      }
    }
    if(n-cnt>=m){
      ++ans;
    }
  }while(next_permutation(p.begin(),p.end()));
  cout<<ans<<"\n";
}

