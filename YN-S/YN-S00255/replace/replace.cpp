#include <bits/stdc++.h>
using namespace std;
const int mod = 3008339;
vector<pair<int, int>> v[mod + 1];
int n, q;
string s[200010][3], temp, temp2, temp3, temp4;
string dif[200010];
int len[200010], pre[200010], nex[200010];
int f[mod + 3];
string t1, t2;

int hash1(string str) {
	int len = str.size();
	long long res = 0;
	for (int i = 0; i < len; i++) {
		res = res * 27 + int(str[i] - 'a') + 1;
		res %= mod;
	}
	return res;
}

int po(int x, int y) {
	long long res = 1, t = x;
	while (y > 0) {
		if ((y & 1) == 1) {
			res *= t;
			res %= mod;
		}
		t *= t;
		t %= mod;
		y = (y >> 1);
	}
	return res;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int len1, ans, hash_t2, hash_t1;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		len[i] = s[i][0].size();
	}
	//ÅÐ¶Ïs[i]Ç°×ººÍºó¼Ì
	for (int i = 1; i <= n; i++) {
		if (s[i][0] == s[i][1]) {
			continue;
		}
		for (int j = 0; j < len[i]; j++) {
			if (s[i][0][j] != s[i][1][j]) {
				pre[i] = j;
				break;
			}
		}
		for (int j = len[i] - 1; j >= 0; j--) {
			if (s[i][0][j] != s[i][1][j]) {
				nex[i] = j;
				break;
			}
		}
		temp = "";
		temp2 = "";
		temp3 = "";
		for (int j = 0; j <= nex[i]; j++) {
			temp += s[i][0][j];
		}
		for (int j = nex[i] + 1; j < len[i]; j++) {
			temp2 += s[i][0][j];
		}
		for (int j = pre[i]; j <= nex[i]; j++) {
			temp3 += s[i][1][j];
		}
		v[hash1(temp)].push_back(make_pair(hash1(temp2), hash1(temp3)));
		//cout << hash1(temp) << endl;
	}
	int fir, las;
	for (int cas = 1; cas <= q; cas++) {
		cin >> t1 >> t2;
		len1 = t1.size();
		for (int i = 0; i < len1; i++) {
			if (t1[i] != t2[i]) {
				fir = i;
				break;
			}
		}
		for (int i = len1 - 1; i >= 0; i--) {
			if (t1[i] != t2[i]) {
				las = i;
				break;
			}
		}
		//cout << fir << " " << las << endl;
		temp = "";
		temp2 = "";
		temp3 = "";
		for (int i = fir + 1; i <= las; i++) {
			temp += t1[i];
			temp2 += t2[i];
		}
		hash_t1 = hash1(temp);
		temp4 = "";
		for (int i = las + 1; i < len1; i++) {
			temp4 += t1[i];
			f[hash1(temp4)] = cas;
		}
		f[0] = cas;
		ans = 0;
		temp2 = t2[fir] + temp2;
		hash_t2 = hash1(temp2);
		int tt = hash_t1;
		temp3 = temp;
		//cout << "325434:" << tt << endl;
		for (int i = fir; i >= 0; i--) {
			temp3 = t1[i] + temp3;
			tt = hash1(temp3);
			tt %= mod;
			//cout << tt << endl;
			int ttt = v[tt].size();
			//cout << "ttt:" << ttt << endl;
			//cout << "i:" << i << endl;
			for (int j = 0; j < ttt; j++) {
				if (f[v[tt][j].first] == cas) {
					//cout << "first" << endl;
					if (v[tt][j].second == hash_t2) {
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}