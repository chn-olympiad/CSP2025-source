#include<iostream>
int n, m;
long long ans = 1;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	if(n != m){
		printf("0");
		return 0;
	}
	for(int i = 1; i <= n; i ++){
		ans = ans * i % 998244353; 
	}
	printf("%lld", ans);
	return 0;
}
//RP++ noWA AC AK !!!
//20

//25 + 32 + 20 + 0 = 77
