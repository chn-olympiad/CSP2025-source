/* “ÏªÚ∫Õ */
                  
#include <bits/stdc++.h>
#define regint register int
using namespace std;

const int MAXN = 5e5+5;
int n;
unsigned long long k;
unsigned long long a[MAXN], b[MAXN];
bool vis[MAXN];
int main(){
	int cnt, l, r;
	bool flg;
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %ull", &n, &k);
	for(regint i = 1; i <= n; i++){
		scanf("%ull", a+i);
		b[i] = b[i-1] ^ a[i];
	}
	
	cnt = 0;
	for(regint i = 0; i < n; i++){
		for(regint j = 1; j <= n-i; j++){
			l = j, r = j+i, flg = true;
			if((b[l-1] ^ b[r]) == k){
				for(regint k = l; k <= r && i; k++){
					if(vis[k]){
						flg = false;
						break;
					}
				}
				if(flg){
					for(regint k = l; k <= r; k++)
						vis[k] = true;
					cnt++;
				}
			}
		}
	}
	printf("%d", cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
