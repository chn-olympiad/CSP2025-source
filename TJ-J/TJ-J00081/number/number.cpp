#include <bits/stdc++.h>
using namespace std;
int a[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	for (int i = 0;i < n;i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[int(s[i] - '0')]++;
		}
	}
	string t = ""; 
	for (int i = 9;i >= 0;i--){
		for (int j = 1;j <= a[i];j++){
			t += (char)i + '0';
		}
	}
	cout << t;
	return 0;
}
