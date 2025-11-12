#include<bits/stdc++.h>
using namespace std;
int s[1000005];
bool cmp(int i1, int i2) {
	return i1>i2;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char i;
	unsigned j = 0;
	while (cin>>i) {
		if (isdigit(i)) {
			s[j++] = int(i-'0');
		}
	}
	sort(s, s+j, cmp);
	for (unsigned l = 0; l < j; l++) {
		cout<<s[l];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
