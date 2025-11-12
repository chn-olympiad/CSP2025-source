#include<bits/stdc++.h>
namespace chuazen{
	#define int long long
	#define max(x,y) (x>y?x:y)
	#define min(x,y) (x<y?x:y)
	#define ufor(i,x,y) for(int i=x;i<=y;i++)
	#define dfor(i,x,y) for(int i=x;i>=y;i--)
	#define N 505
	#define MOD 998244353
	char out[100];
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		int tp=0;
		do{out[++tp]=x%10+'0';x/=10;}while(x);
		while(tp)putchar(out[tp--]);
	}
}
using namespace std;
using namespace chuazen;
int n,m,ans,res;
int cld[N],pre[N],a[N];
int p[N],vis[N];
inline void input(){
	n=read(),m=read();
	char ch;
	ufor(i,1,n){
		ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		cld[i]=ch-'0';
	}
	ufor(i,1,n)a[i]=read();
}
inline void dfs(int dep){
	if(dep==n+1){
		res=0;
		ufor(i,1,n){
			if(cld[i]==0){pre[i+1]=pre[i]+1;continue;}
			if(pre[i]>=a[p[i]]){pre[i+1]=pre[i]+1;continue;}
			res++,pre[i+1]=pre[i];
		}
		if(res>=m)ans++;
		return;
	}
	ufor(i,1,n){
		if(vis[i])continue;
		vis[i]=1,p[dep]=i;
		dfs(dep+1);
		vis[i]=0,p[dep]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	input();
	dfs(1);
	write(ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
