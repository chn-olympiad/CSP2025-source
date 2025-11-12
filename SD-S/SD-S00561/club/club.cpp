#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pii pair<int,int>
using namespace std;

// rp++;

inline ll read() {
	int x=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') x=x*10+c-'0',c=getchar();
	return x*w;
}

const int N=100010;
int T,n,a[N][4],f[310][155][155];

void work1() {
	for(int i=1; i<=n; i++) {
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
	}
	memset(f,128,sizeof f);
	f[0][0][0]=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=n/2; j++) {
			for(int k=0; k<=n/2; k++) {
//					printf("%d %d %d set: %d\n",i+1,j,k,a[i+1][1]);
				f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+1][1]);
				f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[i+1][2]);
				f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[i+1][3]);
			}
		}
	}
	ll ans=0;
	for(int j=0; j<=n/2; j++) {
		for(int k=n/2-j; k<=n/2; k++) {
			ans=max(ans,(ll)f[n][j][k]);
		}
	}
	cout<<ans<<"\n";
}

void work2() {
	for(int i=1; i<=n; i++) {
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
	}
	memset(f,128,sizeof f);
	f[0][0][0]=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=n/2; j++) {
			int k=0;
//				printf("%d %d %d set: %d\n",i+1,j,k,a[i+1][1]);
			f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+1][1]);
			f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[i+1][2]);
			f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[i+1][3]);
		}
	}
	ll ans=0;
	for(int j=0; j<=n/2; j++) {
		ans=max(ans,(ll)f[n][j][0]);
	}
	cout<<ans<<"\n";
}


signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		n=read();
		if(n<=300) {
			work1();
		} else {
			work2();
		}
	}

	return 0;
}
