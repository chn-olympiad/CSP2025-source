#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

string s,a[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int i = 0;
	for (i;i < s.length();i++) if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') a[i] = s[i];
	sort(a,a + i);
	reverse(a,a + i);
	for (int j = 0;j <= i;j++) cout << a[j];
	return 0;	
} 

