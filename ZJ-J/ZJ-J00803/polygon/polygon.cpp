#include<bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, a[5010];
long long ans, p[5010];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	int sum = 0, mx = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);	
		sum += a[i];
		mx = max(mx, a[i]);
	}
	if(sum > mx * 2)
		printf("1\n");
	else
		printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
