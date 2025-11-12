#include<bits/stdc++.h>
using namespace std;
string s1[200010] , s2[200010];
int l[200010] , r[200010] , lenn[200010];

int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		s1[i] = ' ' + s1[i];
		s2[i] = ' ' + s2[i];
		int len = s1[i].size() - 1;
		lenn[i] = len;
		for(int j = 1; j <= len; j++){
			if(s1[i][j] != s2[i][j]){
				if(!l[i]) l[i] = j;
				r[i] = j; 
			}
		}
	} 
	for(int i = 1; i <= q; i++){
		string a , b;
		int ll = 0 , rr = 0;
		cin >> a >> b;
		a = ' ' + a;
		b = ' ' + b;
		int len = a.size() - 1;
		for(int j = 1; j <= len; j++){
			if(a[j] != b[j]){
				if(!ll) ll = j;
				rr = j; 
			}
		}
		int ans = 0;
		for(int j = 1; j <= n; j++){
			if(rr - ll != r[j] - l[j]) continue;
			if(rr < r[j]) continue;
			if(lenn[j] - r[j] > len - rr) continue;
			bool flag = 1;
			for(int k = rr - r[j] + 1; k <= rr - r[j] + lenn[j]; k++){
				if(s1[j][k - rr + r[j]] != a[k] || s2[j][k - rr + r[j]] != b[k]){
					flag = 0;
					break;
				} 
			}
			ans += flag;
		}
		cout << ans << "\n";
	}
	return 0;
}