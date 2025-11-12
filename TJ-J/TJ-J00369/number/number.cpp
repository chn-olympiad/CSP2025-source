#include <bits/stdc++.h>
using namespace std;

string s1; 
int s2[1000010];

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	
	int n = 1;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s1;
	
	for (int i = 0; i < s1.size(); i ++) {
		if ((int)s1[i] >= 48 && (int)s1[i] <= 57) {
			s2[++n] = (int)s1[i] - 48;
		}
	}
	sort(s2 + 1,s2 + 1 + n,cmp);
	
	for (int i = 1; i <= n - 1; i ++) {
		cout << s2[i];
	}
	return 0;
} 
