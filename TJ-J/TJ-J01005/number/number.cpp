#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000006], ind;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			ans[ind++] = s[i] - '0';
		}
	}
	sort(ans, ans + ind, cmp);
	for(int i = 0; i < ind; i++){
		cout << ans[i];
	}
	return 0;
} 
