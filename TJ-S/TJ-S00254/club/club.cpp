#include<bits/stdc++.h>
using namespace std;
int n, t, a[100005], b[100005], c[100005];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int q = 0;q < t;q++){
		cin >> n;
		for(int i = 0;i < n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1,a + n + 1);
		for(int i = n;i > n / 2;i--){
			ans += a[i];
		}
		cout << ans;
	} 
	return 0;
}
