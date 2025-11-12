// hm2ns & sakanaction & RADWIMPS
#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128 i128;
const int N=2e5+5;
string s1[N],s2[N];
int hs1[N],hs2[N];
int h1[N],h2[N];
const int mod=1e9+7;
const int b=31;
i64 pb[N];
int ghs(string s){
  i64 res=0;
  for(char c:s){
    res=(1ll*res*b%mod+c)%mod;
  }
  return res%mod;
}
pair<int,int> mergeh(int h1,int siz1,int h2,int siz2){
  i64 rhs=(1ll*h1*pb[siz2]%mod+h2)%mod;
  int siz=siz1+siz2;
  return make_pair((int)rhs,siz);
}
int gh1(int l,int r){
  if(l>r)return 0;
  return (h1[r]-1ll*h1[l-1]*pb[r-l+1]%mod+mod)%mod;
}
int gh2(int l,int r){
  if(l>r)return 0;
  return (h2[r]-1ll*h2[l-1]*pb[r-l+1]%mod+mod)%mod;
}
int main(){

  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  
  int n,q;cin>>n>>q;
  pb[0]=1;
  for(int i=1;i<=N-5;i++){
    pb[i]=pb[i-1]*b;
  }
  for(int i=1;i<=n;i++){
    cin>>s1[i]>>s2[i];
    hs1[i]=ghs(s1[i]);
    hs2[i]=ghs(s2[i]);
  }
  for(int i=1;i<=q;i++){
    string t1,t2;cin>>t1>>t2;
    int len1=t1.size();int len2=t2.size();
    t1=' '+t1;t2=' '+t2;
    for(int i=1;i<=len1;i++){
      h1[i]=(1ll*h1[i-1]*b%mod+t1[i])%mod;
    }
    for(int i=1;i<=len2;i++){
      h2[i]=(1ll*h2[i-1]*b%mod+t2[i])%mod;
    }
    int ans=0;
    for(int j=1;j<=n;j++){
      int siz=s1[j].size();
      for(int k=1;k+siz-1<=len1;k++){
        int hms=gh1(k,k+siz-1);
        if(hms==hs1[j]){
          int p1=gh1(1,k-1);
          int siz1=((k-1)-1+1);
          int p2=hs2[j];
          int siz2=siz;
          int p3=gh1(k+siz,len1);
          int siz3=(len1-(k+siz)+1);
          
          pair<int,int> m1=mergeh(p1,siz1,p2,siz2);
          
          pair<int,int> m2=mergeh(m1.first,m1.second,p3,siz3);
          
          if(m2.first==h2[len2]){
            ans++;
          }
        }
      }
    }
    cout<<ans<<'\n';
  }

	return 0;
}
