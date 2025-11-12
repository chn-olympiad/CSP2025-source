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
 const int N=505;
 int n,m,c[N],id[N];
 char s[N];
 inline void mian()
 {
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  read(n,m);scanf("%s",s+1);
  fo(i,1,n)read(c[i]),id[i]=i;
  long long ans=0;
  do
  {
   int cnt=0,res=0;
   fo(i,1,n)
   {
    if(cnt>=c[id[i]]){++cnt;continue;}
    if(s[i]=='1')res++;
    else cnt++;
   }
   if(res>=m)ans++;
  }while(next_permutation(id+1,id+1+n));
  wr(ans),pn;
 }
}
signed main(){my_namespace::mian();return 0;}

