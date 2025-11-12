#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
typedef long long ll;
namespace FastIO{
	template<typename T=int>T read(){
		T x=0;int f=1;char c=getchar();
		while(!isdigit(c)){if(c=='-') f=~f+1;c=getchar();};
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		return x*f;
	}
	template<typename T>void write(T x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	template<typename T>void Write(T x,char c='\n'){
		write(x),putchar(c);
	}
}
using namespace FastIO;
const int MOD=998244353;
int f[1<<18][20],c[20],s[20],p[20]; 
void Yorushika(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++) s[i]=getchar()-'0';
	for(int i=0;i<n;i++) c[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		int now=0;
		for(int i=1;i<=n;i++){
			if(now>=c[p[i]-1]||s[i]==0) now++;
		}
		if(now<=n-m) ans++;
	}while(next_permutation(p+1,p+n+1));
	write(ans);
}
int main(){
	file("employ");
	int Tc=1;
	while(Tc--) Yorushika();
	return 0;
}
