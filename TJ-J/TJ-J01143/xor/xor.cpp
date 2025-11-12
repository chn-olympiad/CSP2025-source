#include<iostream>
int n, k;
int a[5000000];
bool stata[50000000];
int xor_, ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	int m = 0;
	for(int i = 0; i < n; i ++){
		if(stata[i]) continue;
		for(int j = i ; j < n; j ++){
			if(stata[j]) continue;
			if(i == j){
				stata[j] = 1;
				xor_ = a[i];
				if(a[i] == k){
					ans ++;
					break;
				}
			}
			xor_ = xor_ ^ a[j];
			if(xor_ == k) {
				ans ++;
				for(int n = i; n <= j; n ++){
					stata[n] = 1;
				}
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
