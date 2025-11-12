#include<bits/stdc++.h>
#define pp putchar(' ')
#define pn putchar('\n')
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define Fo(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>inline void read(T &x)
{
 x=0;int f=1,c=getchar();while(c<'0'||c>'9'){if(c=='-')f^=1;c=getchar();}
 while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48),c=getchar();}x=f?x:-x;
}
template<class T>inline void wr(T x)
{
 if(x<0){putchar('-'),x=-x;}static int buf[21],top=0;while(x){buf[++top]=x%10,x/=10;}
 if(!top){buf[++top]=0;}while(top){putchar(buf[top--]^'0');}
}
template<class T,class ...A>inline void read(T &x,A &...a){read(x),read(a...);}
namespace my_namespace
{
 using ll=long long;
 const int N=1e5+5,INF=1e9;
 int n,a[N][3],t[N],m;
 struct node
 {
  int val,i,j;
  bool operator<(const node &b) const
  {
   return val>b.val;
  }
 } b[N*3];
 bool vis[N];
 int cnt[3],tt[N];
 vector<int>c[3];
 inline void solve()
 {
  read(n);m=0;
  fo(i,1,n)vis[i]=false,tt[i]=-INF;
  fo(i,1,n)
  {
   read(a[i][0],a[i][1],a[i][2]);
   fo(j,0,2)b[++m]={a[i][j],i,j};
  }
  sort(b+1,b+1+m);
  cnt[0]=cnt[1]=cnt[2]=0;
  fo(i,0,2)c[i].clear();
  ll ans=0;
  fo(i,1,m)if(!vis[b[i].i])
  {
   vis[b[i].i]=true,++cnt[b[i].j];
   c[b[i].j].push_back(b[i].i);ans+=b[i].val;
  }
  int tmp=3;fo(i,0,2)if(cnt[i]>n/2)tmp=i;
  if(tmp==3){wr(ans),pn;return;}
  for(int i:c[tmp])fo(j,0,2)if(j!=tmp&&a[i][j]-a[i][tmp]>tt[i])tt[i]=a[i][j]-a[i][tmp];
  sort(tt+1,tt+1+n,[&](int i,int j){return i>j;});
  fo(i,1,n)
  {
   if(cnt[tmp]<=n/2)break;
   --cnt[tmp],ans+=tt[i];
  }
  wr(ans),pn;
 }
 inline void mian()
 {
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int T;read(T);
  while(T--)
  {
   solve();
  }
 }
}
signed main(){my_namespace::mian();return 0;}

