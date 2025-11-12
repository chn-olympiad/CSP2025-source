#include <bits/stdc++.h>
using namespace std;

long long box[128];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (long long i = 0;i <= s.size() - 1;i++){
		box[s[i]]++;
	}
	for (long long i = '9';i >= '0';i--){
		while(box[i]--){
			cout << char(i);
		}
	}
	return 0;
}
