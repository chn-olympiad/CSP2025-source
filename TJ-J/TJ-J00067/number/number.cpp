#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string b,a;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] <= '9' && s[i] >= '0'){
		    b.push_back(s[i]);
		}
	}
	sort(b.begin(),b.end());
	for (int i = b.size() - 1; i >= 0; i--){
		a.push_back(b[i]);
	}
	cout << a;
	return 0;
}
