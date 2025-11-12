#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,c[505],f[20][20][(1<<18)+2];
char a[505];
/*
18 1
111111111111111111
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
*/
inline void add(int &x, int y) {
	x+=y;
	if(x>=M) x-=M;
}
namespace A {
	int cnt[505];
	void main() {
		sort(c+1,c+1+n);
		int ans=1, jc=1;
		for(int i=1; i<=n; i++) jc=1ll*jc*i%M;
		for(int i=1; i<=n; i++) {
			if(a[i]=='0') cnt[n]++;
			else cnt[i-1]++;
		}
		for(int i=n-1; i>=0; i--) cnt[i]+=cnt[i+1];
		for(int i=n; i>=1; i--) {
			int x=cnt[c[i]]-(n-i);
			if(x<=0) {
				cout<<jc;
				return;
			}
			ans=1ll*ans*x%M;
		}
		cout<<(jc-ans+M)%M;
	}
}
namespace B {
	void main() {
		int jc=1;
		for(int i=1; i<=n; i++) jc=1ll*jc*i%M;
		for(int i=1; i<=n; i++) {
			if(a[i]=='0') {
				cout<<0;
				return;
			}
		}
		for(int i=1; i<=n; i++) {
			if(c[i]==0) {
				cout<<0;
				return;
			}
		}
		cout<<jc;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,a+1);
	for(int i=1; i<=n; i++) scanf("%d",&c[i]);
	if(m==1) {
		A::main();
		return 0;
	}
	if(m==n) {
		B::main();
		return 0;
	}
	f[0][0][0]=1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=n; j++) {
			for(int s=0; s<(1<<n); s++) {
				if(!f[i][j][s]) continue;
				for(int p=1; p<=n; p++) {
					if(a[i+1]=='1') {
						if(!(s&(1<<p-1))) {
							if(i-j>=c[p]) add(f[i+1][j][s|(1<<p-1)],f[i][j][s]);
							else add(f[i+1][j+1][s|(1<<p-1)],f[i][j][s]);
						}
					} else {
						add(f[i+1][j][s|(1<<p-1)],f[i][j][s]);
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=m; i<=n; i++) add(ans,f[n][i][(1<<n)-1]);
	cout<<ans;
	return 0;
}