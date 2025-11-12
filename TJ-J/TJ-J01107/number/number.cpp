#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b){
	return a > b;
}
int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s, ch;
	cin >> s;
	for(int i = 0;i < s.size();i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			ch += s[i];
		}
	}
	sort(ch.begin(), ch.end(), cmp); 
	cout << ch;
	
	return 0;
}
