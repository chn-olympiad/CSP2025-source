//前缀异或和 + 区间枚举 = 部分分

#include <bits/stdc++.h>
using namespace std;

int n , k , cnt;
long long a[114514] , vis[114514];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
//		sum[i] = a[i] ^ sum[i - 1];
	}
//	
//	for(int i = 1; i <= n; i++){
//		cout << sum[i] << ' ';
//	}
//	cout << endl;
//	
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			int t = 0 , f = 1;
			for(int i = l; i <= r; i++){
				t ^= a[i];
				if(vis[i] == 1){
					f = 0;
				}
			}
			if(t == k && f == 1){
				cnt++;
				for(int i = l; i <= r; i++){
					vis[i] = 1;
				}
//
				
//			
			}
//			cout << l << ' ' << r << ' ' << t << ' ' << f << endl;
		}
	}
	
	cout << cnt;
	return 0;
} 
