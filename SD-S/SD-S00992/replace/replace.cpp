#include<bits/stdc++.h>
using namespace std;
const int maxn = 222222,maxq = 222222;
int n,q;
string s[maxn][5],t[maxq][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int j = 1;j <= q;j++){
		cin >> t[j][1] >> t[j][2];
		int f,l,ans = 0;
		for(int i = 1;i <= n;i++){
			string tf = t[j][1];
			while(tf.find(s[i][1]) <= t[j][1].size()){
				f = tf.find(s[i][1]);
				int ls = s[i][1].size(),lt = t[j][1].size();
				tf[f] = '|';
				for(int k = 0;k < lt;k++){
					if(k >= f&&k <= f+ls-1)t[j][3] += s[i][2][k-f];
					else t[j][3] += t[j][1][k];
					//cout << t[j][3][k];
				}
				//cout << j << ' ' << i << ' ' << s[i][1] << ' ' << s[i][2] << ' ' << t[j][3] << ' ' << t[j][2] << ' ' << t[j][1] << endl;
				if(t[j][3] == t[j][2])ans++;
				t[j][3] = "";
			}
		}
		cout << ans << endl;
	}
	return 0;
}


