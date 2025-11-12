#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> vec;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen(" ", "r", stdin);
	freopen(" ", "W", stdout);
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len; i++){
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			vec.push_back(s[i] - '0');
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i];
	}
	return 0;
}
