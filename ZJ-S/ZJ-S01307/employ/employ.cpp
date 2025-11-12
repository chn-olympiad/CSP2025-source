#include<iostream>
using namespace std;
const int mod = 998244353;
const int N = 505;
bool vis[N];
long long a[N];
long long cal[N], q;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(m == 1){
		int cnt = 0, ans = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '0')
				cnt++;
			else{
				if(a[i+1] >= cnt);
					ans++;
			}
		}
		cout << ans;
	}
	else{
		cal[0] = 1;
		for(int i = 1; i <= n; i++){
			cal[i] = (cal[i-1] * i * 1ll) % mod;
		}	
		cout << (cal[n]/cal[m])/cal[n-m];
	}
	
	return 0;
}
