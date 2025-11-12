#include<bits/stdc++.h>
using namespace std;

string s;
int ans[1000005], k = 0;

bool cmp(int a, int b){
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);	

	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			ans[k] = s[i] - '0';
			k++;
		}
	}
	sort(ans, ans + k, cmp);
	
	for(int i = 0; i < k; i++){
		cout << ans[i];
	}
	
	return 0;
} 
