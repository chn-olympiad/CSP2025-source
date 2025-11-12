#include<iostream>
#include<algorithm>
int n, m;
int a[1000];
int main(){
	freopen("seat.in", "r", stdin);
  	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n * m; i ++){
		scanf("%d", &a[i]);
	}
	int xiaoR = a[0], xiaoR_P;
	std::sort(a, a + (n * m), std::greater<int>());
	for(int i = 0; i < n * m; i ++){
		if(xiaoR == a[i]){
			xiaoR_P = i + 1;
			break;
		}
	}
	int c = 0;
	if(xiaoR_P % n != 0){
		c = xiaoR_P / n + 1;
		printf("%d ", c);
	}else{
		c = xiaoR_P / n;
		printf("%d ", c);
	}
	if(c % 2 == 0){
		printf("%d", c * n - xiaoR_P + 1);
	}else{
		printf("%d", n - c * n + xiaoR_P);
	}
	return 0;
}
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
