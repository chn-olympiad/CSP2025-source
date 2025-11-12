#include <bits/stdc++.h>
using namespace std;
int a[5010];
int qian[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		qian[i] = qian[i - 1] + a[i];
	}
	int sum = 0;
	for (int len = 3;len <= n;len++){
		for (int l = 1;l <= n - len + 1;l++){
			int r = l + len - 1;
			int mx = 0;
			for (int i = l;i <= r;i++){
				mx = max(mx,a[i]);
			}
			int k = qian[r] - qian[l - 1];
			if (k > mx * 2) sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
