#include<iostream>
#include<cstring>
using namespace std;
int n, w, maxn = -1;
const int N = 1e5+5;
int a[N][4], f[4], cmp[N];
bool flag1, flag2, flag3;
void dfs(int x, int sum){
	if(x > n){
		maxn = max(sum, maxn);
		return ;
	}
	for(int i = 1; i <= 3; i++){
		if(f[i] < w){
			f[i]++;
			dfs(x+1, sum+a[x][i]);
			f[i]--;
		}
	}
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		memset(a, 0, sizeof(a));
	//	memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		memset(cmp, 0, sizeof(cmp));
		maxn = 0;
		cin >> n;
		bool flag = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
			if(a[i][3] == 1)
				flag = 1;
		}
		w = n/2;
		if(!flag){
			for(int i = 1; i <= n; i++){
				if(a[i][2] > a[i][1] && f[2] < w)
					cmp[i] = max(a[i][2], a[i][1]), f[2]++;
				else if(f[1] < w)
					cmp[i] = max(a[i][2], a[i][1]), f[1]++;
			}
			for(int i = 1; i <= n; i++)
				maxn += cmp[i];
		}
		else{
			dfs(1, 0);	
		}
		cout << maxn << '\n';

	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
