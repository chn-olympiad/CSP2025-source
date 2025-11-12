#include<bits/stdc++.h>
using namespace std;
int a[5010], n;
vector<vector<int> >ans;
void dfs(int dep, int p, int k, vector<int>c){
	if(dep == k){
		ans.push_back(c);
		return;
	}
	if(n-p < k-dep) return;
	for(int i = p; i <= n; i++){
		c.push_back(a[i]);
		dfs(dep+1, p, k, c);
		c.pop_back(); 
	}
}
void res(){
	vector<int>x;
	int answer = 0;
	for(int i = 3; i <= n; i++){
		x.clear();
		dfs(0, 1, i, x);
	}
	for(int i = 0; i < ans.size(); i++){
		int cnt = 0;
		for(int j = 0; j < ans[i].size(); j++){
			cnt += ans[i][j];
		}
		if(cnt > 2*ans[i][ans[i].size()-1]) answer++;
	}
	cout << answer;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	res();
	return 0;
}
