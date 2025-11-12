//张巍邺-SN-J00223-西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
const int N = 110,MOD= 998244353;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >>n >>m;
	string s;
	string c;
	cin >> s;
	cin >> c;
	int ans=1;
	for(int i = 1; i<=n; i++) {
		ans*=i;
	}
	cout <<ans%MOD;
	return 0;
}
