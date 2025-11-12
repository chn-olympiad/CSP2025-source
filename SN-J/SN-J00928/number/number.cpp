#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005], cnt;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i <= s.size(); i++)
	{
		if('0' <= s[i] and s[i] <= '9') {
			a[cnt] += s[i] - '0';
			cnt++;
		}
	}
	sort(a, a + cnt);
	for(int i = cnt - 1; i >= 0; i--)
	{
		cout << a[i];
	}
	return 0;
}
