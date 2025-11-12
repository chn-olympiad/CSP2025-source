#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200];
bool sel[200];int cnt = 0;
void dfs(int ind){
	if(ind == n + 1){
		int maxx = -1,summ = 0;
		for(int i =1;i<=n;i++){
//			cout << sel[i] << " ";
			if(!sel[i]) continue;
			maxx = max(maxx,a[i]);
			summ += a[i];
		}
//		cout << (maxx * 2 < summ) << endl;
		if(maxx * 2 < summ){
			cnt++;
		}
		cnt %= 998244353;
		return;
	}
	sel[ind] = 1;
	dfs(ind + 1);
	sel[ind] = 0;
	dfs(ind + 1);
	return;
}
int f_pow(int n){
	if(n == 1) return 2;
	if(n % 2 == 1) return 2*f_pow(n-1) % 998244353;
	else {
		int ret = f_pow(n/2);
		return ret*ret % 998244353;
	} 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int maxxx = 1;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		if(a[i]!= 1) maxxx = 0;
	}
	//cout << maxxx;
	if(!maxxx){
//		cout << 111111111;
		dfs(1);
		cout << cnt - 1;
	}
	else{
//		cout <<11111111;
		cout << f_pow(n) - (n)*(n-1)/2 - n - 1;
	}
	return 0;
}
