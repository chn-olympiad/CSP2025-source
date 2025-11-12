#include <bits/stdc++.h>
#include <vector>
using namespace std;
int a[4];
int b[4];
bool cmp(int x, int y){
	return x > y;
}
vector<int> ans;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "W", stdout);
	int t, n;
	int first, second, third;
	cin >> t;
	while(t--){
		cin >> n;
		int v = 1;
		cin >> a[1] >> a[2] >> a[3];
		cin >> b[1] >> b[2] >> b[3];
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 3; j++){
				if(i != j){
					ans.push_back(a[i] + b[j]);		
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		cout << ans[0] << endl;
		for(int i = 1; i <= ans.size(); i++) ans.pop_back();
	}
	return 0;
}
