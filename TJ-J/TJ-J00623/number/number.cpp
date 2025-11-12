#include <bits/stdc++.h>
using namespace std;

string s;
char t[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	int idx = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			t[idx] = s[i];
			idx++;
		}
	}
	
	sort(t , t + idx , greater<char>());
	
	for(int i = 0; i < idx; i++){
		cout << t[i];
	}
	return 0;
}
