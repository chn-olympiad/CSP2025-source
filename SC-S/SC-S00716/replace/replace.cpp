#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m;
string mod[N][2];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ){
		cin >> mod[i][0] >> mod[i][1];
	}
	while(m -- ){
		string s, im; cin >> s >> im;
		int sl = s.size();
		int cnt = 0;
		for(int i = 1; i <= n; i ++ ){
			int len = mod[i][0].size();
			for(int j = 0; j + len - 1 < sl; j ++ ){
				if(s.substr(j, len) == mod[i][0] && s.substr(0, j) + mod[i][1] + s.substr(j + len, sl - j - len) == im){
					cnt ++ ;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}