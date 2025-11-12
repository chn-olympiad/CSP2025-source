//SN-J00141 刘益铭 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;

int n;

string s,t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	for(int i = 9;i>=0;i--) {
		for(int j = 0;j<n;j++) {
			if(s[j] == (i + '0')) cout << i;
		}
	}
	return 0;
}
