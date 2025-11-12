#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int MaxN = 1e2+10;
Int n, m;
Int c, r;
Int a[MaxN];

Int tmp;
Int cnt = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld", &n, &m);
	for(Int i = 1; i <= n*m; i ++){
		scanf("%lld", &a[i]);
	}
	tmp = a[1];
	for(Int i = 2; i <= n*m; i ++){
		if(a[i] > tmp){
			cnt ++;
		}
	}
	c = (cnt-1)/n+1;
	printf("%lld ", c);
	if(c&1){
		if(cnt%n == 0){
			printf("%lld",n);
		} else {
			printf("%lld",cnt%n);
		}
	} else {
		printf("%lld",n-(cnt-1)%n);
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

2 4
18 90 13 37
91 32 12 31
*/
