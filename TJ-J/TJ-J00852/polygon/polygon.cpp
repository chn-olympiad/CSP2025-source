#include<bits/stdc++.h>
using namespace std;
int a[5010];
int sum[5010];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int mx = -1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	if(n == 3){
		if((a[1] + a[2] + a[3]) > (mx * 2)){
			printf("1");
			return 0;
		}
		else{
			printf("0");
			return 0;
		}
	}
	int s = n * n - 1 * n - 2;
	for(int i = 3; i <= n - 1; i++){
		s *= 2;
		s *= n - i;
	}
	printf("%d", s % 998244353);
	return 0;
}
