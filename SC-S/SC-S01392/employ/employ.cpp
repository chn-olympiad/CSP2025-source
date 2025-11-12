#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 510,NN = 19,P = 998244353;

char c[N];
vector<int> g[N];
int n,m,a[N],f[NN][NN][1 << NN];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	scanf("%s",c + 1);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	if(n <= 18){
		int ans = 0;
		for(int s = 0;s < (1 << n);s++){
			int num = 0;
			for(int i = 1;i <= n;i++)
				num += ((s >> (i - 1)) & 1);
			g[num].push_back(s);
		}
		f[0][0][0] = 1;
		for(int i = 1;i <= n;i++)
			for(int j = 0;j <= i;j++)
				for(int s : g[i])
					for(int k = 1;k <= n;k++){
						if(((s >> (k - 1)) & 1) == 0) continue;
						if(i - j < a[k] && c[i] == '1' && j)
							(f[i][j][s] += f[i - 1][j - 1][s ^ (1 << (k - 1))]) %= P;
						else (f[i][j][s] += f[i - 1][j][s ^ (1 << (k - 1))]) %= P;
					}
		for(int i = m;i <= n;i++)
			(ans += f[n][i][(1 << n) - 1]) %= P;
		printf("%lld\n",ans);
		return 0;
	}
	bool flag = 1;
	for(int i = 1;i <= n;i++)
		if(a[i] == 0) flag = 0;
	if(!flag) puts("0");
	else{
		int ret = 1;
		for(int i = 1;i <= n;i++)
			(ret *= i) %= P;
		printf("%lld\n",ret);
	}
	return 0;
}