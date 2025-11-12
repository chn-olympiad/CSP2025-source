// hm2ns & sakanaction & RADWIMPS
#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128 i128;
const int mod=998244353;
const int N=1000;
vector<int> c1;
int l[N];
int main(){

  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  int n,m;cin>>n>>m;
  string s;cin>>s;
  s=' '+s;
  for(int i=1;i<=n;i++){
    cin>>l[i];
    c1.push_back(i);
  }
  if(n<=10){
    int ans=0;
    do{ 
      int cnt=1;
      int bnd=0;
      int ok=0;
      for(int v:c1){
//        cout<<v<<' ';
        if(bnd>=l[v])bnd++;
        else if(s[cnt]=='0')bnd++;
        else if(s[cnt]=='1')ok++;
        cnt++;
      }
//      cout<<'\n';
      if(ok>=m)ans++;
    }while((next_permutation(c1.begin(),c1.end())));
    cout<<ans;
  }
  else if(n==m){
    i64 res=1;
    for(int i=1;i<=n;i++){
      res=res*i%mod;
      if(s[i]!='1'){
        cout<<0;
        return 0;
      }
    }
    cout<<res;
    return 0;
  }
  else if(m==1){
    i64 res=1;
    sort(l+1,l+1+n);
    for(int i=1;i<=n;i++){
      res=res*i%mod;
    }
    if(l[1]>0&&s[1]=='1')cout<<res;
    else return 0;
    return 0;
  }

	return 0;
}
