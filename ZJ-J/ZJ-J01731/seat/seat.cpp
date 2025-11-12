#include<bits/stdc++.h>
using namespace std;
int n, m;
struct node{
	int cj, r, c;
}a[110];
bool cmp(node x, node y){
	return x.cj < y.cj;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int maxn = 0;
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i].cj);
		maxn = max(maxn, a[i].cj);
	}
	int p = a[1].cj;
	int q;
	if(maxn == p){
		printf("1 1");
		return 0;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	a[n * m].r = 1;
	a[n * m].c = 1;
	int row = 1;
	for(int i = n * m - 1; i >= 1; i--){
		if(a[i].cj == p)q = i;
		if(row % 2 == 1){
			a[i].c = a[i + 1].c + 1;
			a[i].r = a[i + 1].r;
		}
		if(row % 2 == 0){
			a[i].c = a[i + 1].c - 1;
			a[i].r = a[i + 1].r;
		}
		if(a[i + 1].c == n && row % 2 == 1){
			a[i].r = a[i + 1].r + 1;
			a[i].c = a[i + 1].c;
			row++;
			continue;
		}
		if(a[i + 1].c == 1 && row % 2 == 0){
			a[i].r = a[i + 1].r + 1;
			a[i].c = a[i + 1].c;
			row++;
			continue;
		}	
	}
	printf("%d %d", a[q].r, a[q].c);
	return 0;
}

