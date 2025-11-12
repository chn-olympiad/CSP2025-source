#include<bits/stdc++.h>
#define int long long
#define signed bool __End;signed
using namespace std;
bool __Begin;
namespace _IO{inline int read(){int f=1,res=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){res=res*10+(ch-'0');ch=getchar();}return f*res;}void write(int x){if(x<0){putchar('-');write(-x);}else if(x<=9){putchar(x+'0');}else{write(x/10);putchar(x%10+'0');}return;}}
namespace _Min{int Min(int x,int y){return x<y?x:y;}int Max(int x,int y){return x>y?x:y;}}

using namespace _IO;
using namespace _Min;

const int mod=998244353;
int n,m,ans;
char s[2000005];
int c[2000005];
int p[2000005];
int Add(int x,int y){
	return (x+y)%mod;
}
int Mul(int x,int y){
	return 1ll*x*y%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	do{
		int lst=0,tot=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')lst++;
			else{
				if(lst<c[p[i]])tot++;
				else lst++;
			}
		}
		if(tot>=m)ans++;
	}while(next_permutation(p+1,p+1+n));
	write(ans);
//	cerr<<"\n"<<(clock())<<"ms "<<(((&__Begin)-(&__End))>>20)<<"MB\n";
	return 0;
}
