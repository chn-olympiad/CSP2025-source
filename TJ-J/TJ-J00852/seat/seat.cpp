#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	int l = n * m;
	int k;
	for(int i = 1; i <= l; i++){
		scanf("%d", &a[i]);
		if(i == 1){
			k = a[i];
		}
	}
//	printf("%d\n", k);
	sort(a + 1, a + 1 + l, cmp);
	int ki;
	for(int i = 1; i <= l; i++){
//		printf("%d ", a[i]);
	}
	for(int i = 1; i <= l; i++){
		if(a[i] == k){
			ki = i;
		}
	}
//	printf("\n%d\n", ki);
	int kn = ceil(double(ki) / n), km = 0;
	if(kn % 2 != 0){
		km = ki % n;
		if(km == 0){
			km = n;
		}
	}
	else{
		km = n - (ki % n) + 1;
	}
	printf("%d %d", kn, km);
	return 0;
}
