#include<bits/stdc++.h>
using namespace std;
int s[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	//char c;
	//cin >> c;
	string a;
	cin >> a;
	//while(c -'0' >= 0){
	//	cin >> c;
	//	if(c - '0' < 10){
	//		s[c-'0']++;
	//	}
	//}
	for(int i = 0; i < a.size(); i++){
		if(a[i] - '0' < 10){
			s[a[i]-'0']++;
		}
	}
	int i = 10;
	string str = "";
	while(i--){
		for(int j = 1; j <= s[i]; j++){
			str += '0' + i;
		}
	}
	cout << str;
	return 0;
}
