#include<bits/stdc++.h>
#define PII pair<int,int>
#define fir first
#define sec second 
#define ll long long
#define ull unsigned long long
bool MED;
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
int n,q,lens[N],b[N],lenf[N],t[26],p[M];
vector<PII> P[N];
string sf[N],st[N];
string qf[N],qt[N];
namespace solve2{
  struct node{
    int fr,to,chg;//表示前面应该至少有fr个a,b的位移量是chg,正前负后 
  }a[N];
  void solve(){
    for(int i=1;i<=n;i++){
      int fr,to;
      for(int j=1;j<=lens[i];j++)if(sf[i][j]=='b')fr=j;
      for(int j=1;j<=lens[i];j++)if(st[i][j]=='b')to=j;
      a[i]={fr,to-fr};
    }
    sort(a+1,a+1+n,[&](node a,node b){return a.chg==b.chg?a.fr<b.fr:a.chg<b.chg;});
    for(int i=1;i<=n;i++)b[i]=a[i].chg;
    int m=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++){
      int p=lower_bound(b+1,b+1+m,a[i].chg)-b;
      P[p].push_back({a[i].fr,lens[i]-a[i].to+1});
    }
    for(int i=1;i<=q;i++){
      int fr,to;
      for(int j=1;j<=lenf[i];j++)if(qf[i][j]=='b')fr=j;
      for(int j=1;j<=lenf[i];j++)if(qt[i][j]=='b')to=j;
      int p=lower_bound(b+1,b+1+m,to-fr)-b,c=0;
      if(b[p]!=to-fr){cout<<0<<"\n";continue;}
      for(auto v:P[p])if(v.fir>=fr&&v.sec>=lenf[i]-to+1)c++;
      cout<<c<<"\n";
    }
  }
}
namespace solve1{
  const int N=2005;
  ull B[N],hshsf[N][N],hshst[N][N],hshqf[N][N],hshqt[N][N];
  int pre[N],suf[N];
  ull getsf(int p,int l,int r){return hshsf[p][r]-hshsf[p][l-1]*B[r-l+1];}
  ull getst(int p,int l,int r){return hshst[p][r]-hshst[p][l-1]*B[r-l+1];}
  ull getqf(int p,int l,int r){return hshqf[p][r]-hshqf[p][l-1]*B[r-l+1];}
  ull getqt(int p,int l,int r){return hshqt[p][r]-hshqt[p][l-1]*B[r-l+1];}
  void solve(){
    B[0]=1;for(int i=1;i<N;i++)B[i]=B[i-1]*131;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=lens[i];j++)hshsf[i][j]=hshsf[i][j-1]*131+sf[i][j]-'a'+1;
      for(int j=1;j<=lens[i];j++)hshst[i][j]=hshst[i][j-1]*131+st[i][j]-'a'+1;
    }
    for(int i=1;i<=q;i++){
      for(int j=1;j<=lenf[i];j++){
        if(qf[i][j]!=qt[i][j]){
          if(!pre[i])pre[i]=j;
          suf[i]=j;
        }
      }
      int res=0;
      for(int j=1;j<=lenf[i];j++)hshqf[i][j]=hshqf[i][j-1]*131+qf[i][j]-'a'+1;
      for(int j=1;j<=lenf[i];j++)hshqt[i][j]=hshqt[i][j-1]*131+qt[i][j]-'a'+1;
      for(int h=1;h<=n;h++){
        for(int j=1;j<=lenf[i]-lens[h]+1;j++){
          if(getst(h,1,lens[h])==getqt(i,j,j+lens[h]-1)){
            if(getsf(h,1,lens[h])==getqf(i,j,j+lens[h]-1)){
              if(pre[i]>=j&&suf[i]<=j+lens[h]-1){
                res++;
              }
            }
          }
        } 
      }
      cout<<res<<"\n";
    }
  }
}
bool MST;
int main(){
  //fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  freopen("replace.in","r",stdin);
  //freopen("1.out","w",stdout);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>n>>q;
  int FLB=1;
  for(int i=1;i<=n;i++){
    cin>>sf[i]>>st[i];sf[i]=" "+sf[i],st[i]=" "+st[i];
    lens[i]=sf[i].size()-1;
    memset(t,0,sizeof t);
    for(int j=1;j<=lens[i];j++){
      t[sf[i][j]-'a']++;
      if(sf[i][j]>'b'||(t[sf[i][j]]=='b'&&t[sf[i][j]]>1))FLB=0;
    }
    memset(t,0,sizeof t);
    for(int j=1;j<=lens[i];j++){
      t[st[i][j]-'a']++;
      if(st[i][j]>'b'||(t[st[i][j]]=='b'&&t[st[i][j]]>1))FLB=0;
    }
  }
  for(int i=1;i<=q;i++){
    cin>>qf[i]>>qt[i];
    lenf[i]=qf[i].size();qf[i]=" "+qf[i],qt[i]=" "+qt[i];
  }
  if(n<=2000){solve1::solve();return 0;}
  if(FLB)solve2::solve();
  return 0;
}
