#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[200050][2];
int check(string s1,string s2,string s3,string s4){
	int res = 0;
	int len3 = s3.size();
	s3 = ' ' + s3;
	for (int i = 1; i <= len3 - s1.size() + 1; i++){
		string s = s3.substr(i,s1.size());
		if (s == s1){
			string sss = s3.substr(1,i - 1);
			sss += s2;
			sss += s3.substr(i + s1.size(),len3 - (i + s1.size() - 1));
//			cout << sss << ' ' << s4 << endl;
			if (sss == s4){
				res++;
			}
		}
	}
	return res;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 0; i < q; i++){
		int ans = 0;
		string str1,str2;
		cin >> str1 >> str2;
		for (int i = 0; i < n; i++){
			ans += check(s[i][0],s[i][1],str1,str2);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
