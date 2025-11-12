#include<bits/stdc++.h>
using namespace std;
#define FINISH
int a[500010], qzh[500010];
int n, k;
int l[500010], r[500010], sum = 1;
int main(){
#ifdef FINISH
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
#endif
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <=  n; i++){
		scanf ("%d", a + i);
		qzh[i] = qzh[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if((qzh[j] ^ qzh[i - 1]) == k){
				bool flag = true;
				for (int o = 1; o < sum; o++){
					if(l[o] <= i && r[o] >= i || l[o] >= j && r[o] <= j){
						flag = false;
						break;
					}
				}
				if(flag){
					l[sum] = i, r[sum] = j;
					sum++;
				}
			}
		}
	}
	printf("%d", sum - 1);
	return 0;
}
