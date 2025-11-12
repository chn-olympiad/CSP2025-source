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
 using ull=unsigned ll;
 const ll bas=13331,mod=1e9+9;
 const int N=2e5+5,L=5e6+5;
 int n,q;
 string s[N][2];
 vector<int>hs[N][2];
 ll ht[2][L],pw[L];
 inline void mian()
 {
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(0);
  pw[0]=1;fo(i,1,L-1)pw[i]=pw[i-1]*bas%mod;
  cin>>n>>q;
  fo(i,1,n)
  {
   cin>>s[i][0]>>s[i][1];
   int m=s[i][0].length();s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1];
   hs[i][0].resize(m+1),hs[i][1].resize(m+1);hs[i][0][0]=hs[i][1][0]=0;
   fo(k,0,1)fo(j,1,m)hs[i][k][j]=(hs[i][k][j-1]*bas+s[i][k][j]-'a')%mod;
  }
  while(q--)
  {
   string t1,t2;
   cin>>t1>>t2;int m=t1.length();t1=" "+t1,t2=" "+t2;
   ht[0][0]=ht[1][0]=0;
   fo(i,1,m)ht[0][i]=(ht[0][i-1]*bas%mod+t1[i]-'a')%mod;
   fo(i,1,m)ht[1][i]=(ht[1][i-1]*bas%mod+t2[i]-'a')%mod;
   int ans=0;
   fo(i,1,m)
   {
    //cerr<<i<<" ";
    fo(j,1,n)
    {
     int l=i,r=i+(s[j][0].length()-1)-1,len=s[j][0].length()-1;
     if(r!=m&&(ht[0][m]-ht[0][r]*pw[m-r]%mod+mod)%mod!=(ht[1][m]-ht[1][r]*pw[m-r]%mod+mod)%mod)continue;  
//     cerr<<l<<" "<<r<<endl;
     if(hs[j][0][len]!=(ht[0][r]-ht[0][l-1]*pw[r-l+1]%mod+mod)%mod)continue;
     if(hs[j][1][len]!=(ht[1][r]-ht[1][l-1]*pw[r-l+1]%mod+mod)%mod)continue;
     ans++;//cerr<<r<<" ";
    }
    if(t1[i]!=t2[i])break;
   }
   wr(ans),pn;
  }
 }
}
signed main(){my_namespace::mian();return 0;}

