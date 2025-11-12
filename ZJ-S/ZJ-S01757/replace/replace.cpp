#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 10;
int n, q, ans;
string st[5];
string s[N][5];
int begin(string s_1, string s_2){
	int len = s_1.size();
	for(int i = 0; i < n; i++){
		if(s_1[i] != s_2[i]){
			return i;
		}
	}
}
int last(string s_1, string s_2){
	int len = s_1.size();
	for(int i = n - 1; i >= 0; i--){
		if(s_1[i] != s_2[i]){
			return i;
		}
	}
}
string _ss1(string s_1, string s_2){
	int len = s_1.size();
	string s_ = "";
	for(int i = begin(s_1, s_2); i <= last(s_1, s_2); i++){
		s_ += s_1[i];
	}
	return s_;
}
string _ss2(string s_1, string s_2){
	int len = s_1.size();
	string s_ = "";
	for(int i = begin(s_1, s_2); i <= last(s_1, s_2); i++){
		s_ += s_2[i];
	}
	return s_;
}
string begin_ss1(string s_1, string s_2){
	int l = 0, r = begin(s_1, s_2) - 1;
	string s_ = "";
	for(int i = l; i <= r; i++){
		s_ += s_1[i];
	}
	return s_;
}
string begin_ss2(string s_1, string s_2){
	int l = 0, r = begin(s_1, s_2) - 1;
	string s_ = "";
	for(int i = l; i <= r; i++){
		s_ += s_2[i];
	}
	return s_;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("reclace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 2; j++){
			cin >> s[i][j];
		}
	}
	string st1, st2;
	while(q--){
		ans = 0;
		cin >> st1 >> st2;
		int len = st1.size();
		for(int i = 1; i <= n; i++){
			if  (_ss1(s[i][1], s[i][2]) == _ss1(st1, st2) &&
				_ss2(s[i][1], s[i][2]) == _ss2(st1, st2) &&
				begin_ss1(st1, st2) == begin_ss2(st1, st2)){
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
