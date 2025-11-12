#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353,maxn = 5e3+5;
int n,a[maxn];
long long c[maxn][maxn],ans=0;
bool f;
bool cmp(int x,int y){
	return x > y;
}
int p[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0;i <= n+1;i++){
		for (int j = 0;j <= i;j++){
			if (i == 0 || j == i || j == 0) c[i][j]=1;
			else c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		f = (a[i]!=1);
	}
	if (!f){
		for (int i = 3;i <= n;i++){
			ans = (ans+c[n][i])%mod;
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	//cout << a[1];
	cout << ans;
	return 0;
}
