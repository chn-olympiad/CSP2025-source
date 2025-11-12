#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e6 + 7;
map<string,string> mp;
long long n,m,ans;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i ++){
		cin >> a >> b;
		mp[a] = b;
	}
	for (long long i = 1;i <= m;i ++){
		cin >> a >> b;
		ans = 0;
		long long L = 0,R = a.size() - 1;
		for (long long j = 0;j < a.size();j ++){
			if (a[j] != b[j]){
				L = j;
				break;
			}
		}
		for (long long j = a.size() - 1;j >= 0;j --){
			if (a[j] != b[j]){
				R = j;
				break;
			}
		}
		for (long long j = 0;j <= L;j ++){
			string str = "",Str = "";
			for (long long k = j;k < R;k ++){
				str += a[k];
				Str += b[k];
			}
			for (long long k = R;k < a.size();k ++){
				str += a[k];
				Str += b[k];
				if (mp[str] == Str){
					ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}