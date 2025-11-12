#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,m,a[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for(int i = 1;i <= n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++m] = s[i] - '0';
		}
	}
	sort(a + 1,a + m + 1);
	reverse(a + 1,a + m + 1);
	for(int i = 1;i <= m;i++){
		cout << a[i];
	}
	return 0;
}
