#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n,a[1000005];
bool cmp(int x,int y) { return x > y; }
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i<s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[i] = int(s[i] - '0');
			n++;
		}
	}
	sort(a,a + s.size(),cmp);
	for(int i = 0;i<n;i++) {
		cout << a[i];
	}
	return 0;
}
