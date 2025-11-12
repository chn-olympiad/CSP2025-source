#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
char a[1000010];
int top = 0;

int main() {
	fropen("number.in", "r", stdin);
	fropen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for(int i = 0; i < l; i++)
		if(s[i] >= '0' && s[i] <= '9')
			a[++top] = s[i];
	sort(a + 1, a + top + 1);
	for(int i = top; i; i--)
		cout << a[i];
	cout << '\n';
	return 0;
}
