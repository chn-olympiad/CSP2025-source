#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar 
#define pc putchar  
const int N=1e5+15;
struct node{
	
};int maxn[N],a[N][5];
inline int read(){
	int d=1,k=0;char c=gc();
	while(!(c>='0'&&c<='9'||c=='-'))c=gc();
	if(c=='-')c=gc(),d=-1;
	while(c>='0'&&c<='9')k=(k<<1)+(k<<3)+(c^48),c=gc();
	return d*k;
}inline void write(int x){
	static int sta[50];int top=0;
	do{sta[top++]=x%10;x/=10;}while(x);
	while(top)pc(sta[--top]+'0');puts("");
}signed main(){memset(maxn,-1,sizeof maxn);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	int T=read();while(T--){
//		int n=read();for(int i=1;i<=n;++i)for(int j=1;j<=3;++j)a[i][j]=read(),maxn[i]=max(maxn[i],a[i][j]);
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=3;++j){
//				if(!check(j,n))continue;
//				if(check(j,n))dp[i][j]+=max(dp[i][j-1],dp[i-1][j]+maxn[i]);
//			}
//		}
//		write(dp[n][3]);
//		for(int i=1;i<=n;++i){
//			maxn[i]=-1;
//			for(int j=1;j<=3;++j)dp[i][j]=0;
//		}
//	}
	int T=read();while(T--){
		int maxn=-1,n=read();for(int i=1;i<=n;++i)for(int j=1;j<=3;++j)a[i][j]=read(),maxn=max(maxn,a[i][j]);
		write(maxn);
	}
	return 0;
}/*
߇߈߉ߊ
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
