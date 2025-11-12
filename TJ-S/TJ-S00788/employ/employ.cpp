#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 23
#define N 300005
const int mod=998244353;

int n,m,p2[M],a[M],op[M],ans,siz[N];
int f[N][M];
char ch;
void Add(int &x,int y) {
	x+=y; if(x>=mod) x-=mod;
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::cin>>n>>m,p2[0]=1;
	for(int i=1;i<M;i++) p2[i]=p2[i-1]*2;
	for(int i=1;i<N;i++) siz[i]=siz[i/2]+(i&1);
	for(int i=1;i<=n;i++)
		std::cin>>ch,op[i]=(ch=='1');
	for(int i=1;i<=n;i++) std::cin>>a[i];
	f[0][0]=1;
	for(int i=0;i<p2[n];i++) {
		for(int k=0;k<=n;k++) {
			if(!f[i][k]) continue;
			for(int j=1;j<=n;j++) {
				if(i&p2[j-1]) continue;
				if(!op[siz[i]+1]||k>=a[j]) Add(f[i^p2[j-1]][k+1],f[i][k]);
				else Add(f[i^p2[j-1]][k],f[i][k]);
			}
		}
	}
	for(int i=m;i<=n;i++) Add(ans,f[p2[n]-1][n-i]);
	std::cout<<ans;
	return 0;
}