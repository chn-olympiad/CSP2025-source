#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100005],b[100005],c[100005],f[101][101][101],t,n;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	bool flag = true;
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0 || c != 0) flag = false;
		}
		if (flag == true){
			sort(a+1,a+n+1,cmp);
			int ans = 0;
			for (int i = 1;i <= n/2;i++) ans += a[i];
			cout << ans << endl;
			continue;
		}
		for (int p = 1;p <= n;p++){
			int q = ceil(p/2.0);
			for (int i = 0;i <= q;i++)
				for (int j = 0;j <= min(q,p-i);j++){
					int k = p-i-j; 
					if (k > q) continue;
					if (i != 0)
						f[i][j][k] = max(f[i][j][k],f[i-1][j][k]+a[p]);
					if (j != 0)
						f[i][j][k] = max(f[i][j][k],f[i][j-1][k]+b[p]);
					if (k != 0)
						f[i][j][k] = max(f[i][j][k],f[i][j][k-1]+c[p]);
				}
		}
		n /= 2;
		int ans = 0;
		for (int i = 0;i <= n;i++)
			for (int j = 0;j <= n;j++)
				for (int k = 0;k <= n;k++){
					if (i+j+k == n*2) ans = max(ans,f[i][j][k]);
					f[i][j][k] = 0;
				}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
