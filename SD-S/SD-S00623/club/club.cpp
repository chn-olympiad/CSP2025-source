#include<bits/stdc++.h>
#define LL long long
using namespace std;
//_______________________________________________________________________________________________________
const int N = 100009;
struct AC{
	int x1, x2, x3;
};
bool cmp1(AC x, AC y){
	int dx = x.x1 - max(x.x2, x.x3);
	int dy = y.x1 - max(y.x2, y.x3);
	return dx < dy;
}
bool cmp2(AC x, AC y){
	int dx = x.x2 - max(x.x1, x.x3);
	int dy = y.x2 - max(y.x1, y.x3);
	return dx < dy;
}
bool cmp3(AC x, AC y){
	int dx = x.x3 - max(x.x2, x.x1);
	int dy = y.x3 - max(y.x2, y.x1);
	return dx < dy;
}
int T, n;

vector<AC> g[4];

void doit(){
	int ans = 0;
	g[1].clear(); g[2].clear(); g[3].clear();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int w1, w2, w3;
		scanf("%d%d%d", &w1, &w2, &w3);
		AC a = {w1, w2, w3};
		if(w1 >= w2 && w1 >= w3){
			g[1].push_back(a);
			ans += w1;
		}
		else if(w2 >= w1 && w2 >= w3){
			g[2].push_back(a);
			ans += w2;
		}
		else{
			g[3].push_back(a);
			ans += w3;
		}
	}
	if(g[1].size() > n / 2){	
		sort(g[1].begin(), g[1].end(), cmp1);
		for(int i = 0; g[1].size() - i - 1 >= n / 2; i++){
			ans -= g[1][i].x1 - max(g[1][i].x2, g[1][i].x3);
//			printf("!!!%d\n", ans);
		}
	}
	if(g[2].size() > n / 2){	
		sort(g[2].begin(), g[2].end(), cmp2);
		for(int i = 0; g[2].size() - i - 1 >= n / 2; i++){
			ans -= g[2][i].x2 - max(g[2][i].x1, g[2][i].x3);
//			printf("!!!%d\n", ans);
		}
	}
	if(g[3].size() > n / 2){	
		sort(g[3].begin(), g[3].end(), cmp3);
		for(int i = 0; g[3].size() - i - 1 >= n / 2; i++){
			ans -= g[3][i].x3 - max(g[3][i].x1, g[3][i].x2);
//			printf("!!!%d\n", ans);
		}
	}
	printf("%d\n", ans);
}


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		doit();
	}

	return 0;
}

