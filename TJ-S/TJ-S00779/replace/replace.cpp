#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2+5;

int n, q;
string s[N][2], t[2];

inline int check(int j, int k)
{
	string tmp = t[0];
	for(size_t i = 0; i < s[j][0].length(); i++) {
		tmp[i+k] = s[j][0][i];
	}
//	bool flag = true;
	for(size_t i = 0; i < t[0].length(); i++) {
		if(tmp[i] != t[1][i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for(int i = 1; i <= q; i++) {
		cin >> t[0] >> t[1];
		int ans = 0;
		for(int j = 1; j <= n; j++) {
			for(size_t k = 0; k < t[0].length(); k++) {
				if(k+s[j][0].length()>=t[0].length()) break;
				bool flag = true;
				for(size_t l = 0; l < s[j][0].length(); l++) {
					if(s[j][0][l] != t[0][k+l])  {
						flag = false; 
						break;
					}
				}
				if(flag) {
//					printf("check(%d %d)\n", j, k);
					ans += check(j,k);
				}
			}
		}
		cout << ans << "\n";
	}



	return 0;
}

//check WA/RE/MLE/TLE

