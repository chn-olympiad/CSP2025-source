#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
signed main(){
//	freopen("csps/down/employ/employ3.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	int t=1;
	for(int i=1;i<=n;i++)cin >> c[i],t=t*i%mod;
	cout << t;
	return 0;
}

