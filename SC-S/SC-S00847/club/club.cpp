#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//#define int ll
const int N=1e5+5;
template<typename T=int>inline T read(){
	T x=0;bool f=false;char c=getchar();
	while(c<'0'||c>'9') f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return f?-x:x;
}
int T,n,c[4],res;
struct Person{int a[4];}p[N];
namespace SUB1_11{
	int res,dp[2][105][105][105];
	inline int main(){
		memset(dp,0,sizeof dp);
		res=0;
		for(int i=1,j;i<=n;++i){
			for(int c1=0;c1<=n/2;++c1){
				for(int c2=0,c3;c2<=n/2;++c2){
					c3=i-c1-c2-1,j=i&1;
					dp[j][c1+1][c2][c3]=max(dp[j][c1+1][c2][c3],dp[1-j][c1][c2][c3]+p[i].a[1]);
					dp[j][c1][c2+1][c3]=max(dp[j][c1][c2+1][c3],dp[1-j][c1][c2][c3]+p[i].a[2]);
					dp[j][c1][c2][c3+1]=max(dp[j][c1][c2][c3+1],dp[1-j][c1][c2][c3]+p[i].a[3]);
				}
			}
		}
		for(int c1=0;c1<=n/2;++c1) for(int c2=0;c2<=n/2;++c2)
			for(int c3=0;c3<=n/2;++c3) res=max(res,dp[n&1][c1][c2][c3]);
		return res;
	}
}
namespace SUBA{
	int res;
	inline bool cmp(Person x,Person y){
		return x.a[1]>y.a[1];
	}
	inline int main(){
		res=0;
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n/2;++i) res+=p[i].a[1];
		return res;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		bool A=true;
		n=read(),res=c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j) p[i].a[j]=read();
			if(p[i].a[2]!=0||p[i].a[3]!=0) A=false;
		}
		if(n<=200) res=SUB1_11::main();
		else if(A) res=SUBA::main();
		printf("%d\n",res);
	}
	return 0;
}