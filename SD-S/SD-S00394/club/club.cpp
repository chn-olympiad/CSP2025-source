// hm2ns & sakanaction & RADWIMPS
#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef __int128 i128;

const int N=1e5+114;
struct work{
  int id;
  int gr;
  int det;
  bool operator<(const work &x)const{
    return x.det>det;
  }
};
int cntrr[N];
int ph[N][5];
priority_queue<work> wk[4];
void init(){
  for(int i=0;i<=3;i++)
    while(wk[i].size())wk[i].pop();
  return ;
}
void solve(){
  int n;cin>>n;
  int mxn=n/2;
  i64 ans=0;
  for(int i=1;i<=n;i++){
    int bst=-0x3f3f3f3f;
    int r=0;
    for(int j=1;j<=3;j++){
      cin>>ph[i][j];
      if(bst<ph[i][j])bst=ph[i][j],r=j;
    }
    int det=-0x3f3f3f3f;
    int rg=0;
    for(int j=1;j<=3;j++){
      if(j==r)continue;
      if(det<ph[i][j]-bst)det=ph[i][j]-bst,rg=j;
    }
    if(wk[r].size()<mxn){
      wk[r].push(work{i,rg,det});
      ans+=bst;
    }
    else{
      if(wk[r].top().det+bst<0){
        int snd=-0x3f3f3f3f;
        int r1=0;
        for(int j=1;j<=3;j++){
          if(j==r)continue;
          if(snd<ph[i][j])snd=ph[i][j],r1=j;
        }
        int det1=-0x3f3f3f3f;
        int rg2=0;
        for(int j=1;j<=3;j++){
          if(j==r1)continue;
          if(det1<ph[i][j]-snd)det1=ph[i][j]-snd,rg2=j;
        }
        wk[r1].push(work{i,rg2,det1});
        ans+=snd;
      }
      else{
        work pd=wk[r].top();
        wk[r].pop();
        wk[r].push(work{i,rg,det});
        ans+=bst;
        ans+=pd.det;
        int bst1=ph[pd.id][pd.gr];
        int det1=-0x3f3f3f3f;
        int rg3=0;
        for(int j=1;j<=3;j++){
          if(j==pd.gr)continue;
          if(det1<ph[pd.id][j]-bst1)det1=ph[pd.id][j]-bst1,rg3=j;
        }
        wk[pd.gr].push(work{pd.id,rg3,det1});
      }
    }
  }
  for(int i=1;i<=3;i++){
    while(wk[i].size()){
      work rr;
      rr=wk[i].top();
      if(rr.det+wk[rr.gr].top().det>0){
        work rr1=wk[i].top();
        wk[i].pop();
        work rr2=wk[rr.gr].top();
        wk[rr.gr].pop();
        
        ans+=rr1.det;
        ans+=rr2.det;
        
        int bst1=ph[rr1.id][rr1.gr];
        int det1=-0x3f3f3f3f;
        int rg3=0;
        for(int j=1;j<=3;j++){
          if(j==rr1.gr)continue;
          if(det1<ph[rr1.id][j]-bst1)det1=ph[rr1.id][j]-bst1,rg3=j;
        }
        wk[rr1.gr].push(work{rr1.id,rg3,det1});
        
        bst1=ph[rr2.id][rr2.gr];
        det1=-0x3f3f3f3f;
        rg3=0;
        for(int j=1;j<=3;j++){
          if(j==rr2.gr)continue;
          if(det1<ph[rr2.id][j]-bst1)det1=ph[rr2.id][j]-bst1,rg3=j;
        }
        wk[rr2.gr].push(work{rr2.id,rg3,det1});
        
      }
      else wk[i].pop();
    }
  }
  cout<<ans<<'\n';
  return ;
}
int main(){

  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  
//  ios::sync_with_stdio(0);
//  cin.tie(0);
  int T;cin>>T;
  while(T--){
    init();
    solve();
  }

	return 0;
}

