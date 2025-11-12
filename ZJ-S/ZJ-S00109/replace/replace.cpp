#include <bits/stdc++.h>
using namespace std;
int n, q, ans = 0, cnt = 0, num = 0;
string s[200005][2], t1, t2;
set <string> se;
void dfs(string ss){
	if (ss == t2){
		ans ++;
		return ;
	}
	for (int i=1; i <= n; i++){
		for (int j=0; j < ss.size(); j++){
			for (int k=j; k < ss.size(); k++){
				if (ss.substr(j, k) == s[i][0]){
					string st = ss.substr(0, j-1) + s[i][1] + ss.substr(k+1);
					if (!se.count(st)){
						se.insert(st);
						dfs(st);
					}
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i=1; i <= n; i++)  cin >> s[i][0] >> s[i][1];
	if (q == 1){
		ans = 0;
		cin >> t1 >> t2;
		dfs(t1);
		cout << ans << "\n";
	}
	return 0;
}
/*
This is too hard for me. I just can't figure it out. :(
I even have one hour left, but I think even if there are six hours left, or even if I had just started this compitition, I still can't wort this out.
I think I'll only have 80pts or less. Maybe next time will be better.
Goodbye, Hangzhou. It's time for me to go back to Huzhou.
I think today is just a sweet dream, maybe.
------ muchenguxing
*/
