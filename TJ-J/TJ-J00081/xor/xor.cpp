#include <bits/stdc++.h>
using namespace std;
int a[500010];
int biao[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int sum0 = 0;
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if (a[i] == 0) sum0++;
	}
	if (k == 0){
		printf("%d",sum0);
		return 0;
	}
	int cnt = 0;
	for (int len = 1;len <= n;len++){
		for (int l = 1;l <= n - len + 1;l++){
			int r = l + len - 1;
			int f = 0;
			if (f) continue;
			int sum = a[l];
			for (int i = l + 1;i <= r;i++){
				sum = sum ^ a[i];
			}
			if (sum == k) cnt++;
		}
	} 
	printf("%d",cnt); 
	return 0;
} 
