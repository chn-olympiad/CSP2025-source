#include<bits/stdc++.h>
using namespace std;
int a[500010], l[10];
int cnt;
int si, n, k;
struct node{
	int l;
	int r;
}m[1000000];
bool t[500010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	bool f = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt ^= a[i];
		if(a[i] == 0 && a[i - 1] == 1 && cnt == 1){
			cnt = 0;
		}
		if(cnt == k){
			ans++;
			cnt = 0;
		}
	}
	printf("%d", ans);
	return 0;
}
