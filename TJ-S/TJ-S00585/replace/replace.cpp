#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
long long n, q, a[N], ans;
char s[N][3][N], s3[3][N], s1[N], s2[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	int i, k1, k2, ok, l, j;
	for(i = 1; i <= n; i ++){
		scanf("%s %s", s[i][1], s[i][2]);
	}
	while(q --){
		memset(a, 0, sizeof(a));
		l = k1 = ok = ans = 0;
		scanf("%s %s", s1, s2);
		if(strlen(s1) != strlen(s2)){
			printf("0\n");
			continue;
		}
		for(i = 0; i < strlen(s1); i ++){
			if(s1[i] != s2[i]){
				a[i] = 1;
				if(ok){
					for(j = k1; j < i; j ++) a[j] = 1;
				}
			}
			if(a[i] == 0 && a[i - 1] == 1) ok = 1, k1 = i;
		}
		for(i = 0; i < strlen(s1); i ++){
			if(a[i]) s3[1][l] = s1[i], s3[2][l] = s2[i], l ++;
		}
		for(i = 1; i <= n; i ++){
			ok = 0;
			if(strlen(s[i][1]) == strlen(s3[1])){
				for(j = 0; j < strlen(s3[1]); j ++){
					if(s[i][2][j] != s3[2][j] || s[i][1][j] != s3[1][j]) ok = 1;
				}
				if(!ok) ans ++;
			}
			if(strlen(s1) == strlen(s[i][1])){
				ok = 0;
				for(j = 0; j < strlen(s1); j ++){
					if(s1[j] != s[i][1][j] || s2[j] != s[i][2][j]) ok = 1;
				}
				if(!ok) ans ++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
