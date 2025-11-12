#include <iostream>

using namespace std;

#define ll long long 

struct node{
	int rp, num;
};

const ll Mod = 998244353;
int n, m;
string s;
int c[510];
node a[510];
ll cnt;

void dfs(int y, node a[]){
	if(y == n){
		int cntt = 0;
		for(int i = 1; i <= n; i ++)
			if(s[i] == '1' && i - cntt < a[i].rp) cntt ++;
		if(cntt >= m) cnt ++;
		cnt %= Mod;
		return;
	}
	for(int i = 1; i <= n; i ++){
		int c1 = 0;
		for(int j = 1; j <= y; j ++)
			if(a[j].num == i){
				c1 = 1;
				break;
			}
		if(c1 == 1) continue;
		a[y].num = i;
		a[y].rp = c[i];
		dfs(y + 1, a);
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	
	cin >> s;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	for(int i = 1; i <= n; i ++){
		a[1].rp = c[i];
		a[1].num = i;
		dfs(2, a);
	}
	cout << cnt % Mod << endl;
}
