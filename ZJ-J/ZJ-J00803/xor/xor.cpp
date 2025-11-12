#include<bits/stdc++.h>
using namespace std;
int n, k, a[500010], s0, s1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	bool ok = true;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);	
		if(a[i] == 1)
			s1++;
		else
			s0++;
		if(a[i] != 1)
			ok = false;
	}
	if(ok && k == 0){
		printf("0\n");
		return 0;
	}
	if(k == 0)
		printf("%d\n", s0);
	else if(k == 1)
		printf("%d\n", s1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
