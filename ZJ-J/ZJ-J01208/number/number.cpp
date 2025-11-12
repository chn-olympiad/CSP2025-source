#include <iostream>
#include <algorithm>

int t[51];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::string s;
	std::cin >> s;
	for(char c : s)
		if(c <= '9' and c >= '0')
			t[c - '0']++;
	for(int i = 9;i >= 0;i--){
		int x = t[i];
		while(x--)
			printf("%d", i);
	}
	return 0;
}