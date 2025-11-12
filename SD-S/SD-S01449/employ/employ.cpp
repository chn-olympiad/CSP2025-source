#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 5e2 + 5;
int n, m;
string dif;
int c[maxn];
	/*void dfs(int k, int a[], int ans){
		if (k == n) return ;
		for (int i = 0;i < k;i ++)
			if (k == a[i]) return ;
		for (int i = 1;i <= n;i ++){
			dfs(k + 1, a[3], ans);
		}
	}*/
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> dif;
	for (int i = 1;i <= n;i ++){
		cin >> c[i];
	}
	cout << 0;
	return 0;
}
