#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '9'){
			cout << "9";
		}
		else if(s[i] == '8'){
			cout << "8";
		}
		else if(s[i] == '7'){
			cout<< "7";
		}
		else if(s[i] == '6'){
			cout << "6";
		}
		else if(s[i] == '5'){
			cout << "5";
		}
		else if(s[i] == '4'){
			cout << "4";	
		}
		else if(s[i] == '3'){
			cout << "3";
		}
		else if(s[i] == '2'){
			cout << "2";
		}
		else if(s[i] == '1'){
			cout << "1";
		}
		else if(s[i] == '0'){
			cout << "0";
		}
	} 
	return 0;
}
