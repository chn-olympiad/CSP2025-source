#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
inline int read(){
	int s=0,w=1;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?(-1):1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return s*w;
}
int n,m,a[N];
char op[N];
namespace sub1{
	int f[(1<<18)+5][20];
	int lowbit(int x){ return x&(-x); }
	void work(){
		f[0][0]=1;
		int all=(1<<n)-1,ans=0;
		for(int s=0;s<(1<<n);s++){
			for(int i=0;i<=n;i++){
				if(!f[s][i]) continue;
				if(s==all){
					if(i>=m) (ans+=f[s][i])%=mod;
					continue;
				}
				int siz=__builtin_popcount(s),lst=siz-i;
				for(int T=all^s;T;T-=lowbit(T)){
					int x=__lg(lowbit(T))+1;
					if(op[siz+1]=='0') (f[s^lowbit(T)][i]+=f[s][i])%=mod;
					else{
						if(lst>=a[x]) (f[s^lowbit(T)][i]+=f[s][i])%=mod; 
						else (f[s^lowbit(T)][i+1]+=f[s][i])%=mod;   
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,op+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=18) sub1::work();
 	return 0;
}

