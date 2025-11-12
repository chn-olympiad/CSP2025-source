#include<bits/stdc++.h>
using namespace std;
const int maxn = 5*1e5+10;
//int a[maxn][maxn];
int s[maxn];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, is = 0;
	long long k;
	int ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		int a = s[1];
		if(k == 0){
			if(s[i] == 1 && is == 1){
				ans++;
				is = 0;
			}else if(s[i] == 1 && is == 0){
				is = 1;
			}else{
				continue;
			}
		}else{
			if(s[i] == 1) ans++;
		}
	}
	//a[1][1] = s[1];
	//for(int i = 1; i <= n; i++){
	//	for(int j = i; j<= n; j++){
	//		if(i = j){
	//			a[i][j] = s[i];
	//		}else{
	//			a[i][j] = s[j] ^ a[i][j-1];
	//		}
	//		if(a[i][j] == k) ans++;
	//	}
	//}
	cout << ans;
	return 0;
}
