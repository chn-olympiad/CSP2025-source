#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50,M = 625;
int T,n,m;
long long a[N],b[N],c[N],ans,f[M][M][M];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T --){
		cin >> n;
		ans = 0;
		m = n / 2;
		int f2 = 1,f3 = 1;
		for(int i = 1;i <= n;i ++){
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] != 0)f2 = 0;
			if(c[i] != 0)f3 = 0;
		}
		if(f2 && f3){
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= m;i ++){
				ans += a[i];
			}
			cout << ans << endl;
			continue;
		}
		for(int i = 0;i <= m;i ++){
			for(int j = 0;j <= m;j ++){
				for(int k = 0;k <= m;k ++){
					f[i][j][k] = 0;
				}
			}
		}
		for(int p = 1;p <= n;p ++){
			for(int i = 0;i <= min(p,m);i ++){
				for(int j = 0;j <= min(p - i,m);j ++){
					int k = p - i - j;
					if(k > m)continue;
					if(i > 0)f[i][j][k] = max(f[i][j][k],f[i - 1][j][k] + a[p]);
					if(j > 0)f[i][j][k] = max(f[i][j][k],f[i][j - 1][k] + b[p]);
					if(k > 0)f[i][j][k] = max(f[i][j][k],f[i][j][k - 1] + c[p]);
					ans = max(ans,f[i][j][k]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
