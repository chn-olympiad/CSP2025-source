#include <bits/stdc++.h>
using namespace std;
long long num[1000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long len = 0;
	for (int i = 0;i < s.size();i++){
		if (s[i] >= '0' && s[i] <= '9'){
			len++;
			num[len] = s[i] - '0';
		}
	}
	sort (num,num + len + 1);
	int ifs = 1;
	for (int i = 1;i <= len;i++){
		if (num[i] != 0){
			ifs = 0;
		}
	}
	if (ifs == 1){
		cout << 0;
		return 0;
	}
	for (int i = len;i >= 1;i--){
		cout << num[i];
	}
	return 0;
}
