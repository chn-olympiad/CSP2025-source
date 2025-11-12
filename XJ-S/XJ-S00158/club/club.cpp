#include <bits/stdc++.h>
using namespace std;
int t, n, a[10^4];
int main(){
	freopen("club".in 'r' cpp);
	scanf("%d%d", &t, &n);
	for(int i=0; i<=n; i++){
		if(i/2==0){
			for(int j=0; j<=i; j++){
				a = max{j[i]};
				printf("%d", a[t]);
			}
		}else if(i/2!=0){
			return 0;
		}
	}
	return 0;
} 
