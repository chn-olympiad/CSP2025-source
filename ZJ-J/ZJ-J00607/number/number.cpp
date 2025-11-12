#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e6 + 10;

int n,m;
char Gin[N];
string s;

bool cmp (char x,char y){ return x > y; }
void solve(){
	cin >> s; n = s.size(); s = " " + s;
	for (int i = 1 ; i <= n ; i++)
		if (s[i] >= '0' && s[i] <= '9') Gin[++m] = s[i];
	sort(Gin + 1,Gin + m + 1,cmp);
	for (int i = 1 ; i <= m ; i++) cout << Gin[i];
	cout << endl;
}
signed main(){
	//freopen("number4.in","r",stdin);
	//freopen("my.txt","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
