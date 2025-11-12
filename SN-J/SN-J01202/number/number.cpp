#include<bits/stdc++.h>
using namespace std;

string s, sa;
int ans;

bool cmp(const int lhs, const int rhs){
	return rhs < lhs;
}

int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);	
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= 48 && s[i] <= 57){
			sa += s[i];
		}
	}
	sort(sa.begin(), sa.end(), cmp);
	cout << sa;
	return 0;
}
