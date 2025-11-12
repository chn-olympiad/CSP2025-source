#include <bits/stdc++.h>
using namespace std;

int n, q;
string ch[5000005][3];
int l[5000005];
string t1, t2;
int delta;
int ans = 0;
int len[5000005];

int main() {
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);

ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 1;i <=n;i++) {
		cin >> ch[i][1] >> ch[i][2];
		len[i] = ch[i][1].size();
		int count1 = 0, count2 = 0;
		for(int m = 0;m < len[i];m++) {
			if(ch[i][1][m] == 'a') count1++;
			if(ch[i][1][m] == 'b') break;
		}
		for(int m = 0;m < len[i];m++) {
			if(ch[i][2][m] == 'a') count2++;
			if(ch[i][2][m] == 'b') break;
		}
		l[i] = count1 - count2;
	}
	//cout << l[1];
	for(int i = 1;i <= q;i++) {
		cin >> t1 >> t2;
		int lenth = t1.size();
		int count1 = 0, count2 = 0;
		for(int m = 0;m < lenth;m++) {
			if(t1[m] == 'a') count1++;
			if(t1[m] == 'b') break;
		}
		for(int m = 0;m < lenth;m++) {
			if(t2[m] == 'a') count2++;
			if(t2[m] == 'b') break;
		}
		delta = count1 - count2;
		//cout << delta;
		for(int j = 1;j <= n;j++) {
			if(l[j] == delta and len[j] <= lenth) ans++;
		}
		cout << ans << endl;
		delta = ans = 0;
	}
	return 0;
}

