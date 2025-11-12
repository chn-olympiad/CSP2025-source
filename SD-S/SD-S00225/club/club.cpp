#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long 
inline int Read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return x*f;
}
inline void Write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) Write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+10;
int T,n,ans;
int a[10][N],lmt[10];
int f[6][N];
bool vis[N];
void dfs(int x,int res){
	if(x==n+1){
		ans=max(ans,res);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(lmt[i]>=1){
			lmt[i]--;
			dfs(x+1,res+a[i][x]);
			lmt[i]++;
		}
	}
}
bool cmp(int A,int B){return A>B;}
bool tpA(){
	for(int j=2;j<=3;j++){
		for(int i=1;i<=n;i++){
			if(a[j][i]!=0) return 0;
		} 
	}
	sort(a[1]+1,a[1]+n+1,cmp);
	ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[1][i];
	}
	printf("%lld\n",ans);
	return 1;
}
void solve(){
	ans=0;
	for(int k=1;k<=3;k++){
		for(int i=1;i<=n;i++){
			f[k][i]=0;
		}
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	n=Read();
	for(int i=1;i<=3;i++) lmt[i]=n/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			a[j][i]=Read();
		}
	}
	if(n<=10){
		dfs(1,0);
		printf("%lld\n",ans);	
		return ;	
	}
	if(tpA()) return ;
	f[1][lmt[1]]=f[2][lmt[2]]=f[3][lmt[3]]=0;
	for(int k=1;k<=3;k++){
		for(int i=1;i<=n;i++){
			for(int j=lmt[k];j>=1;j--){
				if(f[k][j-1]+a[k][i]>f[k][j]){
					f[k][j]=f[k][j-1]+a[k][i];
				}
			}
		}
	}
	ans=0;
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=n/2;j++){
			if(n-i-j>n/2) continue;
			ans=max(ans,f[1][i]+f[2][j]+f[3][n-i-j]);
		}
	}
	printf("%lld\n",ans);

	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=Read();
	while(T--){
		solve();
	}
	return 0 ;
}
