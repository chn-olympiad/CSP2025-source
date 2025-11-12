#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MAXN=2e5+5;
const int M1=1e9+7,M2=1e9+9;
const int B1=131,B2=13331;
const int MAXM=5e6+5;

int len[MAXN];
pair<int,int> h1[MAXN],h2[MAXN];
int pw1[MAXM],pw2[MAXM];
pair<int,int> th1[MAXM],th2[MAXM];

pair<int,int> getth1(int l,int r){
  pair<int,int> res={
    th1[r].fi-1ll*th1[l-1].fi*pw1[r-l+1]%M1,
    th1[r].se-1ll*th1[l-1].se*pw2[r-l+1]%M2
  };
  if(res.fi<0){
    res.fi+=M1;
  }
  if(res.se<0){
    res.se+=M2;
  }
  return res;
}

pair<int,int> getth2(int l,int r){
  pair<int,int> res={
    th2[r].fi-1ll*th2[l-1].fi*pw1[r-l+1]%M1,
    th2[r].se-1ll*th2[l-1].se*pw2[r-l+1]%M2
  };
  if(res.fi<0){
    res.fi+=M1;
  }
  if(res.se<0){
    res.se+=M2;
  }
  return res;
}

int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout); 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;++i){
    string s1,s2;
    cin>>s1>>s2;
    len[i]=s1.size();
    for(int j=0;j<len[i];++j){
      h1[i].fi=(1ll*h1[i].fi*B1+s1[j])%M1; 
      h1[i].se=(1ll*h1[i].se*B2+s1[j])%M2;
      h2[i].fi=(1ll*h2[i].fi*B1+s2[j])%M1;
      h2[i].se=(1ll*h2[i].se*B2+s2[j])%M2;
    }
  }
  pw1[0]=pw2[0]=1;
  for(int i=1;i<MAXM;++i){
    pw1[i]=1ll*pw1[i-1]*B1%M1;
    pw2[i]=1ll*pw2[i-1]*B2%M2;
  }
  while(q--){
    string t1,t2;
    cin>>t1>>t2;
    if(t1.size()!=t2.size()){
      cout<<"0\n";
      continue;
    }
    int m=t1.size();
    t1=" "+t1;
    t2=" "+t2;
    int l=1,r=m;
    while(t1[l]==t2[l]){
      ++l;
    }
    while(t1[r]==t2[r]){
      --r;
    }
    for(int i=1;i<=m;++i){
      th1[i].fi=(1ll*th1[i-1].fi*B1+t1[i])%M1;
      th1[i].se=(1ll*th1[i-1].se*B2+t1[i])%M2;
      th2[i].fi=(1ll*th2[i-1].fi*B1+t2[i])%M1;
      th2[i].se=(1ll*th2[i-1].se*B2+t2[i])%M2;
    }
    int ans=0;
    for(int i=1;i<=n;++i){
      if(len[i]<r-l+1||len[i]>m){
        continue;
      }
      for(int j=l-(len[i]-(r-l+1));j<=l&&j+len[i]-1<=m;++j){
        if(getth1(j,j+len[i]-1)==h1[i]&&getth2(j,j+len[i]-1)==h2[i]){
          ++ans;
        }
      }
    }
    cout<<ans<<"\n";
  }
}

