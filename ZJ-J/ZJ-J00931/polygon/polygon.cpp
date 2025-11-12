#include<bits/stdc++.h>
using namespace std;

int a[5005],ans;

int dfs(int x,int bian,int maxx,int zhi) {
	int shi = 0;
	if(bian >= 3) {
	//cout <<bian << ' '<< zhi <<' '<<maxx<< "      ";
		if(zhi > 2*maxx) {
			shi = 1;
			for(int ci = 1; ci <= x - 1; ci++) {
				shi *= 2;
			}
			return shi % 998244353;
		}
	}
	for(int i=x-1;i>=1;i--) {
		shi += dfs(i,bian+1,maxx,a[i]+zhi);
	}
	return shi % 998244353;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	
	for(int i = n; i >= 1; i--) {
		ans+=dfs(i,1,a[i],a[i]);
	}
	cout << ans % 998244353;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}