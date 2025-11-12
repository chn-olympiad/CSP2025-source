/*
set<string> oier;
oier.erase("jess1ca1o0g3");
*/

#include<bits/stdc++.h>
#define i64 long long

using namespace std;
void solve();

const int N=1e5+5;

int n,ans,a[N],b[N],c[N],f[205][3][205][205];

signed main(){
  freopen("club.in","r",stdin);
  freopen("club.out,","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie();
  int Test=1;
  cin>>Test;
  while(Test--){
    cin>>n;
    ans=0;
    int fl2=0,fl3=0;
    for(int i=1;i<=n;i++){
      cin>>a[i]>>b[i]>>c[i];
      fl2=max(fl2,b[i]);
      fl3=max(fl3,c[i]);
    }
    if(!fl2&&!fl3){
      sort(a+1,a+n+1);
      for(int i=n;i>n/2;i++) ans+=a[i];
      cout<<ans<<endl;
      return 0;
    }
    solve();
  }
}


void solve(){
  for(int i=1;i<=n;i++){
    for(int x=0;x<=min(i,n/2);x++){
      for(int y=0;y<=min(i-x,n/2);y++){
        if(x) f[i][0][x][y]=max({f[i-1][0][x-1][y],f[i-1][1][x-1][y],f[i-1][2][x-1][y]})+a[i];
        if(y) f[i][1][x][y]=max({f[i-1][0][x][y-1],f[i-1][1][x][y-1],f[i-1][2][x][y-1]})+b[i];
        if(i-x-y&&i-x-y<=n/2) f[i][2][x][y]=max({f[i-1][0][x][y],f[i-1][1][x][y],f[i-1][2][x][y]})+c[i];
        ans=max({ans,f[i][0][x][y],f[i][1][x][y],f[i][2][x][y]});
      }
    }
  }
  cout<<ans<<endl;
}