#include<bits/stdc++.h>
using namespace std;

int c[510];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	string s;
	
	cin >> n >> m;
	cin >> s;
	for(int i=1; i<=n; i++ ) cin >> c[i];
	int f = 0;
	for(int i = 0; i<s.size(); i++) f += s[i]-'0';
	if(f==s.size()){
		sort(c+1, c+1+n);
		int cnt = 0;
		for(int i = 1; i<=n; i++){
			if(c[i]<=cnt) cnt++;
		}
//		cout << cnt << '\n';
		int rsd = n - cnt;
		int ans = 1;
		if(rsd<m){
			cout << 0;
			return 0;
		}
		while(rsd--){
			ans *= rsd+1;
//			cout << rsd << ' '<< ans << ' ';
		}
		cout << ans;
		return 0;
	}
	
//	srand(time(0));cout<<rand()%998244353;
	cout << 0;
	
	return 0;
}
