#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
template<typename T>inline void read(T&x){
  x=0;bool f=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
  while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
  if(f)x=~x+1;
}
#define ll long long
const int N=1e5+5;
struct node{
  int a[3],maxn;
  bool operator<(const node&rhs)const{
    return maxn>rhs.maxn;
  }
}a[N];
int n,cnt[3],res;
#define PII pair<int,int>
#define mp make_pair
#define fi first
#define se second
multiset<PII >s[3][3];
void clear(){
  for(int i=0;i<3;++i)for(int j=0;j<3;++j)s[i][j].clear();
  cnt[0]=cnt[1]=cnt[2]=0;res=0;
}
void solve(){
  read(n);
  for(int i=1;i<=n;++i)for(int j=0;j<3;++j)read(a[i].a[j]);
  for(int i=1;i<=n;++i)a[i].maxn=max(a[i].a[0],max(a[i].a[1],a[i].a[2]));
  sort(a+1,a+n+1);
  for(int i=1;i<=n;++i){
    if(cnt[0]<(n>>1)&&cnt[1]<(n>>1)&&cnt[2]<(n>>1)){
      for(int j=0;j<3;++j)
        if(a[i].a[j]==a[i].maxn){
          cnt[j]++;res+=a[i].maxn;
          for(int k=0;k<3;++k)
            if(j!=k)s[j][k].insert(mp(a[i].a[j]-a[i].a[k],i));
          break;
        }
    }else{
      for(int j=0;j<3;++j)
        if(cnt[j]==(n>>1)){
          int ret=-1,p=-1;
          for(int k=0;k<3;++k)
            if(j!=k&&a[i].a[k]>ret)ret=a[i].a[k],p=k;
          int val=-1,l=-1;
          for(int k=0;k<3;++k)
            if(j!=k){
              multiset<PII >::iterator it=s[j][k].begin();PII r=*it;
              if(a[i].a[j]-r.fi>val)val=a[i].a[j]-r.fi,l=k;
            }
          if(val>ret){
            cnt[l]++;res+=val;
            multiset<PII >::iterator it=s[j][l].begin();PII r=*it;
            for(int k=0;k<3;++k)
              if(j!=k)s[j][k].erase(mp(a[r.se].a[j]-a[r.se].a[k],r.se));
            for(int k=0;k<3;++k)
              if(l!=k)s[l][k].insert(mp(a[r.se].a[l]-a[r.se].a[k],r.se));
            for(int k=0;k<3;++k)
              if(j!=k)s[j][k].insert(mp(a[i].a[j]-a[i].a[k],i));
          }else{
            cnt[p]++;res+=ret;
            for(int k=0;k<3;++k)
              if(p!=k)s[p][k].insert(mp(a[i].a[p]-a[i].a[k],i));
          }
          break;
        }
    }
  }
  printf("%d\n",res);
  clear();
}
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int T;read(T);while(T--)solve();
  return 0;
}
