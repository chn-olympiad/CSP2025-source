#include<bits/stdc++.h>
#define N 1000500
#define ed puts("")
//#define mod 1000000007
#define p_ putchar(' ')
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar(45);
		x=~x+1;
	}
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top) putchar(sta[--top]+48);
	return;
}
struct node{
	int a,b,c,maxn;
}a[N];
int T,n,num,cnt[5],ans,cnt11,dp[203][203][203];
bitset<N> vis;
bool cmp(node a,node b){
	return a.maxn>b.maxn;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i].a=read(),a[i].b=read(),a[i].c=read();
			a[i].maxn=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].b==0&&a[i].c==0) ++cnt11;
		}
		sort(a+1,a+n+1,cmp);
		if(cnt11==n){
			for(int i=1;i<=n/2;++i) ans+=a[i].maxn;
			write(ans),ed;
			ans=0;
			num=0;
			cnt11=0;
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n;++j){
				for(int k=0;k<=n;++k){
					for(int l=0;l<=n;++l){
						if(j+k+l>n) break;
						if(j) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i].a);
						if(k) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i].b);
						if(l) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i].c);
					}
				}
			}
		}
		for(int j=0;j<=n/2;++j){
			for(int k=0;k<=n/2;++k){
				int l=n-k-j;
				if(l>n/2) continue;
				ans=max(ans,dp[j][k][l]);
			}
		}
		write(ans),ed;
		 
			for(int j=0;j<=n;++j){
				for(int k=0;k<=n;++k){
					for(int l=0;l<=n;++l){
						dp[j][k][l]=0;
					}
				}
			}
		ans=0;
		num=0;
		cnt11=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
