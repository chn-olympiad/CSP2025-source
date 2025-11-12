#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 35;
int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){
		if (s == '-') f=-1;
		s=getchar();
	}while(isdigit(s)){
		x=x*10+s-'0';
		s=getchar();
	}return x*f;
}
int n;
int vis[5];
struct node{
	ll a,b,c;
}p[100030];
ll f[N][N/2][N/2][N/2];
//ll f[105][105][105];
ll dfs(int pos,int c1,int c2,int c3,ll sum){
	
	if (c1+c2+c3 == n) return sum;
	
	if (f[pos][c1][c2][c3]) return f[pos][c1][c2][c3] ;
	ll res = 0;
	if (c1<n/2) res = max(res,dfs(pos+1,c1+1,c2,c3,sum+p[pos].a));
	if (c2<n/2) res = max(res,dfs(pos+1,c1,c2+1,c3,sum+p[pos].b));
	if (c3<n/2) res = max(res,dfs(pos+1,c1,c2,c3+1,sum+p[pos].c));
//	f[pos][c1][c2][c3] = res;
	return res;
}
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b-x.a>y.b-y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _=read();
	while(_--){
		n=read();
		
		int c1=0,c2=0,c3=0;
		ll sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++) {
			p[i].a = read();
			p[i].b = read();
			p[i].c = read();
			sum1+=p[i].a,sum2+=p[i].b,sum3+=p[i].c;
		//	a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		}
//			printf("%d \n",n);

		if (n<=30 ) {
			
			//memset(f,0,sizeof(f));
			printf("%lld\n",dfs(1,0,0,0,0));
		}
		else {
			if (sum2 == 0 && sum3 == 0){
				sort(p+1,p+n+1,cmp1);
				ll ans = 0;
				for(int i=1;i<=n/2;i++) {
					ans += p[i].a;
				}
				printf("%lld\n",ans);
			}else {
				sort(p+1,p+n+1,cmp2);
				ll ans = sum1;
				for(int i=1;i<=n;i++) {
					if (i==n/2+1) break;
					else {
						ans += p[i].b-p[i].a;
					}
				}
				printf("%lld\n",ans);
			} 
		}
//			for(int d=1;d<=n;d++) {
//				for(int i=0;i<min(n/2,d);i++) {
//					for(int j=0;j<min(n/2,d);j++) {
//						for(int k=0;k<min(n/2,d);k++) {
//							f[i+1][j][k] = max(f[i+1][j][k],f[i][j][k]+p[d].a);
//							f[i][j+1][k] = max(f[i][j+1][k],f[i][j][k]+p[d].b);
//							f[i][j][k+1] = max(f[i][j][k+1],f[i][j][k]+p[d].c);
//						}
//					}
//				}
//			}
//			ll ans = 0;
//			for(int i=0;i<=n/2;i++){
//				for(int j=0;j<=n/2;j++) {
//					if (n-(i+j)>n/2) continue;
//					ans = max(ans,f[i][j][n-i-j]);
//				}
//			}	
//			printf("%lld\n",ans);
		
	
	}
		
	return 0;
}/*
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
4 0  0

*/
