#include <bits/stdc++.h>
using namespace std;
int n,a[5];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if (n < 3){
		printf("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	if (a[1] + a[2] + a[3] > 2 * max(a[1],max(a[2],a[3])))
		printf("1");
	else
		printf("0");
	return 0;
}
