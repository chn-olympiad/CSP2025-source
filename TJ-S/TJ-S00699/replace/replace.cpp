#include<iostream>
#include<vector>
using namespace std;
int n, q;
int ans;
char a[50000000], b[50000000], c[50000000], d[50000000];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	while(q --){
		scanf(" %s %s ", a, b);
		while(n--){
			scanf("%s %s", c, d);
			for(int i = 0; a[i] != '\0'; i ++){
				if(a[i] != c[0]) continue;
				bool flag  = 0;
				int j;
				for(j = i; c[j - i] != '\0'; j ++){
					if(a[j] != c[j]){
						flag = 1;
						break;
					}
				}
				if(!flag){
					flag = 0;
					for(int k = i; k <= j; k ++){
						printf("%d", b[j]);
						if(b[j] != d[j]){
							flag = 1;
							break;
						}
					}
					if(!flag){
						ans ++;
					}
				}
			}
		}
		printf("%d", ans);
	}
	return 0;
}
//RP++ noWA AC AK !!!
//10 ~ 0
