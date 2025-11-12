#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
using namespace std;

const int N = 2e5 + 10;
map<string, vector<string>> mp;
int n, q;
int a[4];
ll ans;

void dfs(int n, int id, string t1, string t2){
	if (id == 3){
		string x = t1.substr(0, a[1]);
		string y = t1.substr(a[1], a[2]);
		if ((int)y.size() == 0){
			return ;
		}
		string z = t1.substr(a[1] + a[2]);
		for (int i = 0;i < mp[y].size();i ++){
			if (x + mp[y][i] + z == t2){
				ans ++;
			}
		}
		return ;
	}
	for (int i = 0;i <= n;i ++){
		a[id] = i;
		dfs(n - i, id + 1, t1, t2);
	}
}

int main(){
	fast;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1;i <= n;i ++){
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1].push_back(s2);
	}
	for (int i = 1;i <= q;i ++){
		ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		dfs((int)t1.size(), 1, t1, t2);
		cout << ans << endl;
	}
	
	return 0;
}
