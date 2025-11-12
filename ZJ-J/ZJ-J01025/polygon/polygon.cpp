#include <bits/stdc++.h>
using namespace std;
const int N=5010,M=998244353;
int a[N],b[N][N];
signed main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	int n,c=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	b[1][0]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<N;j++){
			b[i][j]=(b[i-1][j]+b[i][j])%M;
			if(j+a[i-1]<N) b[i][j+a[i-1]]=(b[i-1][j]+b[i][j+a[i-1]])%M;
			else b[i][N-1]=(b[i-1][j]+b[i][N-1])%M;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=N-2;j>=0;j--) b[i][j]=(b[i][j+1]+b[i][j])%M;
		c=(c+b[i][a[i]+1])%M;
	}
	printf("%d",c);
	
	return 0;
}

