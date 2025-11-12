#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define repp(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define getc getchar
#define putc putchar
#define scan scanf
#define prin printf
using namespace std;
const int NM=1e2,N=10,M=10;
int a[NM+10];
int ans[N+10][M+10];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n*m) scanf("%d",a+i);
	int a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,p=1;
	while(1) {
		while(1) {
			ans[i][j]=a[p];
			if(i==n) break;
			++p;
			++i;
		}
//		cerr<<i<<" "<<j<<" "<<p<<endl;
		++p;
		++j;
		if(j>n) break;
		while(1) {
			ans[i][j]=a[p];
			if(i==1) break;
			++p;
			--i;
		}
		++p;
		++j;
		if(j>n) break;
//		cerr<<i<<" "<<j<<" "<<p<<endl;
	}
//	rep(i,1,n) {
//		rep(j,1,m) {
//			cerr<<ans[i][j]<<" ";
//		}
//		cerr<<"\n";
//	}
	rep(i,1,n)
		rep(j,1,m)
			if(ans[i][j]==a1) {
				prin("%d %d",j,i);
				break;
			}
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
*/
