#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,cnt = 1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	vector<ll> a(n+1);
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		cnt*=a[i];
		cnt %= 998244353;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
