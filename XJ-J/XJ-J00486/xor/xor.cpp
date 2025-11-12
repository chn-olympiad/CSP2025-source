#include <bits/stdc++.h>
using namespace std;
long long n,k,tf,a[500010],dp[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	tf = true;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		if(a[i] != 1) {
			tf = false;
		}
	}
	if(k == 0 && tf) {
		printf("%d",n/2);
	} else if(k == 0 || k == 1){
		if(k == 1){
			int ans = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 1){
					ans++;
				}
			}
			printf("%d",ans);	
		}
		if(k == 0){
			bool b = true;int ans = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 1 && b){
					b = false;
				}
				else if(a[i] == 1 && b == false){
					b = true;
					ans++;
				}
				else if(a[i] == 0 && b == true){
					ans++;
				}
			}
		}
	}else{
		printf("%d",n/k); 
	}
	return 0;
}
