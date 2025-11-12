/*
goodbye,OI!
*/

#include<bits/stdc++.h>
#define i64 long long


using namespace std;

void solve();
int n,q;
string s[105][2];

signed main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int Test=1;
//  scanf("%d",&Test);
  while(Test--) solve();
}

void solve(){
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>s[i][0]>>s[i][1];
  }
  while(q--){
    string t1,t2;
    cin>>t1>>t2;
    if(t1.size()!=t2.size()){
      cout<<0<<endl;
      continue;
    }
    i64 ans=0;
    for(int i=0;i<t1.size();i++){
      for(int j=1;j<=n;j++){
        bool ok=1;
        if(i+s[j][0].size()>t1.size()) continue;
        for(int k=0;k<s[j][0].size();k++){
          if(t1[i+k]!=s[j][0][k]){
            ok=0;
            break;
          }
        }
        if(ok){
          for(int k=0;k<i;k++){
            if(t2[k]!=t1[k]){
              ok=0;
              break;
            }
          }
          if(!ok) continue;
          for(int k=i;k<i+s[j][1].size();k++){
            if(t2[k]!=s[j][1][k-i]){
              ok=0;
              break;
            }
          }
          if(!ok) continue;
          for(int k=i+s[j][1].size();k<t2.size();k++){
            if(t2[k]!=t1[k]){
              ok=0;
              break;
            }
          }
          if(ok) ans++;
        }
      }
    }
    cout<<ans<<endl;
  }
}