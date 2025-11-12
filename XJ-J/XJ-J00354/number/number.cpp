#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	char c[2005];
	int sum = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[i] = s[i];
			sum++;
		}
		else{
			continue;
		}
	}
	for(int i = 0; i <= sum + 1; i++){
		if(c[i] < c[i+1]){
			int w;
			w = c[i+1];
			c[i+1] = c[i];
			c[i] = w;
		}
		cout << c[i];
	}
 	return 0;
}
