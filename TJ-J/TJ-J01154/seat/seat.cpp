#include <bits/stdc++.h>
using namespace std;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1 ; i <= n * m ; i++) scanf("%d", &a[i]);
	int flag1 = true, flag2 = true;
	for(int i = 1 ; i <= n* m ; i++){
		if(a[i] != i) flag1 = false;
		if(a[i] != n * m - i + 1) flag2 = false;
	}
	if(flag1) printf("%d %d", m, n);
	if(flag2) printf("1 1");
	return 0;
}
