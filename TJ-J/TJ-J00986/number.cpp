#include <string>
#include<iostream>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int d = 0,f[s.size() + 5],h = 0;
	for (int i = 0;i < s.size();i ++){
		if ('0' <= s[i]&&s[i] <= '9'){
			a[i] = s[i] - '0';
		}
	}
	for (int i = 0;i < s.size();i ++){
		if (s[i] == '0') h ++;
	}
	for (int g = 0;g < s.size();g ++){
		for (int i = 1;i < s.size();i ++){
			if (a[d]< a[i]) d = i;
		}
		if (a[d] == 0) break;
		cout << a[d];
		a[d] = 0;
		d = 0;
	}
	for (int i = 0;i < h;i ++){
		cout << "0";
	}
	return 0;
}
