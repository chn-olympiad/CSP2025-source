#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[5001],b[21],n;
long long cnt;
const int mod = 998244353;
void dfs(int d,int dep){
	if (dep >= d){
		long long ans = 0;
		for (int i = 1;i <= d-1;i++) ans += b[i]*a[i];
		if (ans > a[d]) cnt = (cnt+1) % mod;
		return;
	}
	b[dep] = 1;
	dfs(d,dep+1);
	b[dep] = 0;
	dfs(d,dep+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag = true;
	cin >> n;
	if (n < 3){
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != 1) flag = false;
	}
	if (flag == true){
		long long ans = 1,p = 0;
		for (int i = 1;i <= n;i++)
			ans = (ans*2) % mod;
		ans = (ans-1-n-n*(n-1)/2+mod) % mod;
		cout << ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i = 3;i <= n;i++){
		for (int j = 1;j <= 20;j++) b[i] = 0;
		dfs(i,1);
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
