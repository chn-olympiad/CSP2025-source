#include <cstdio>
#include <algorithm>
int n,m;
int c[107];
int len,b[107];
int x=1,y=1;
int a[17][17];

int xiaoR;
bool first=true;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++) {
		int s;
		scanf("%d",&s);
		if (first) {
			xiaoR=s;
			first=false;
		}
		c[s]++;
	}
	for (int i=100;i;i--) {
		if (c[i]) {
			b[++len]=i;
//			puts("1"); 
		}
	}
//	for (int i=1;i<=len;i++) printf("%d%c",b[i]," \n"[i==len]); 
	for (int i=1;i<=len;i++) {
		a[(i-1)/n+1][(i-1)%n+1]=b[i];
	}
//	for (int i=1;i<=n;i++) {
//		for (int j=1;j<=m;j++) {
//			printf("%3d",a[j][i]);
//		}puts("");
//	}
	for (int i=2;i<=m;i+=2) {
		std::reverse(a[i]+1,a[i]+1+n);
	}
//	for (int i=1;i<=n;i++) {
//		for (int j=1;j<=m;j++) {
//			printf("%3d",a[j][i]);
//		}puts("");
//	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) if (a[j][i]==xiaoR) {
			printf("%d %d\n",j,i);
			return 0;
		}
	}
	return 0;
}
