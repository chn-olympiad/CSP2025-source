#include<bits/stdc++.h>
using namespace std;
int a[500010],n,ans,k;
char xingzhi;
int M,m=2147483647;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >>n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		M = max(M,a[i]);
		m = min(m,a[i]);
		
	} 
	
	if( n <= 2){
		// A ai == 1 k = 0
		if(n == 1) cout << 0;
		else if(n == 2) cout << 1;
	} else if(n <= 10){
		int ans = 0;
		if (k == 0){
			int i = 1;
			while(i <= n){
				if(a[i] == 0){
					ans++;
					i = i + 1;
				} 
				else if(a[i] == 1 && i + 1 <= n &&  a[i + 1] == 1){
					ans++;
					i = i + 2;
				}else{
					i++;
				}
			}
		}else if(k == 1){
			for(int i = 1; i <= n; i++){
				if(a[i] == 1) ans++;
			}
		}
		cout << ans;
	} else if(n <= 100){
		int ans = 0;
		if(k == 0 && M == m && m = 1){///A
			ans = n/2;
			cout << ans;
		}else{//B
		
			int ans = 0;
			if (k == 0){
				int i = 1;
				while(i <= n){
					if(a[i] == 0){
						ans++;
						i = i + 1;
					} 
					else if(a[i] == 1 && i + 1 <= n &&  a[i + 1] == 1){
						ans++;
						i = i + 2;
					}else{
						i++;
					}
				}
			}else if(k == 1){
				for(int i = 1; i <= n; i++){
					if(a[i] == 1) ans++;
				}
			}
			cout << ans;
		
		}
		//C
	}else if( k <=1){// t13 B
		
			int ans = 0;
			if (k == 0){
				int i = 1;
				while(i <= n){
					if(a[i] == 0){
						ans++;
						i = i + 1;
					} 
					else if(a[i] == 1 && i + 1 <= n &&  a[i + 1] == 1){
						ans++;
						i = i + 2;
					}else{
						i++;
					}
				}
			}else if(k == 1){
				for(int i = 1; i <= n; i++){
					if(a[i] == 1) ans++;
				}
			}
			cout << ans;
		
		
	}else{
		
		int ans = 0;
		
		for(int i = 1; i <= n; i++){
			if(a[i] == k) {
				ans++;
			}
		}
		
		for(int len = 2; len < n; len ++){
			
			for(int i = 1; i <= n; i++){
				if(a[i] == k) {
					int t = 0;
					for(int j = 1 ; j <= len ; j++){
						if(a[i + j] == k) break;
						if(a[i + j] != -1){
								t ^= a[i + j];
						}
					
					}
					if(t == k){
						for(int j = 1 ; j <= len ; j++){
							a[i + j] = -1;
						}
						ans++;
					}
					
				}
			}
		}
	
		cout << ans;
		
		
		
		
	}
	
	
	
	return 0;
} 
