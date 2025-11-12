#include<bits/stdc++.h>
//#undef STDIO
const int N = 1e5 + 10;
struct node{
	int x[3], w;
	int mx(){
		int val = std::max({x[0], x[1], x[2]});
		if(x[0] == val) return 0;
		if(x[1] == val) return 1;
		if(x[2] == val) return 2;
		return -1;
	}
}a[N];
std::vector<int> b[3];
int n, t;
int main(){
#ifndef STDIO
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		b[0].clear();
		b[1].clear();
		b[2].clear();
		int sum = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i].x[0], &a[i].x[1], &a[i].x[2]);
			b[a[i].mx()].emplace_back(i);
			sum += a[i].x[a[i].mx()];
		}
		for(int i = 0; i < 3; i++){
			if((int)b[i].size() > (n >> 1)){
				int k1, k2;
				if(i == 0) k1 = 1, k2 = 2;
				else if(i == 1) k1 = 0, k2 = 2;
				else k1 = 0, k2 = 1;
				for(int j = 1; j <= n; j++){
					a[j].w = std::max(a[j].x[k1], a[j].x[k2]) - a[j].x[i];
				}
				std::sort(b[i].begin(), b[i].end(), [] (int x, int y) {
					return a[x].w > a[y].w;
				});
				for(int j = 0; j < (int)b[i].size() - (n >> 1); j++){
					sum += a[b[i][j]].w;
				}
				break;
			}
		}
		printf("%d\n", sum);
	}
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}