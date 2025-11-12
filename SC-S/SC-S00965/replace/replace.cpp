#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn = 2e5 + 55, mod = 998244353, inf = 2147483647;
const double pi = acos(-1);
int T;
int n, q, ans;
string s[maxn][5], t[maxn][5];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1;i <= q;i ++){
		cin >> t[i][1] >> t[i][2];
		ans = 0;
		for(int j = 1;j <= n;j ++){
			if(t[i][1].size() - s[j][1].size() + s[j][2].size() != t[i][2].size()){
				continue;
			}else{
				string tem = t[i][1];
				int last = 0;
				while(((int)tem.find(s[j][1]) != -1) && (tem != "")){
					int k = tem.find(s[j][1]);
					if(k == -1) continue;
					
					string a = t[i][1].substr(0, last + k);
//					cout << a << endl;
					a += s[j][2];
					
					a += tem.substr(k + s[j][2].size(),tem.size() - k - s[j][2].size());
					
					last += k + 1;
					tem = tem.substr(k + 1, tem.size() - 1);
					
					
//					cout << j << " " << a <<" " << k << " " << last << " " << tem << endl;
					if(t[i][2] == a){
						ans ++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}