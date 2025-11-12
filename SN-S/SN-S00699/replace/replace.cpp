#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
int n,m;
ull p1[5000005],p2[5000005],b1 = 131,b2 = 13;
ull h1[5000005],h2[5000005],h3[5000005],h4[5000005];
unordered_map<ull,ull> mp;
string s[200005],t[200005],x,y;
ull q1(int x,int y){
	ull num1 = h1[y] - (h1[x - 1] - 1) * p1[y - x + 1];
	ull num2 = h2[y] - (h2[x - 1] - 1) * p2[y - x + 1];
	return (num1 + num2) ^ (num1 * num2);
}
ull q2(int x,int y){
	ull num1 = h3[y] - (h3[x - 1] - 1) * p1[y - x + 1];
	ull num2 = h4[y] - (h4[x - 1] - 1) * p2[y - x + 1];
	return (num1 + num2) ^ (num1 * num2);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p1[0] = p2[0] = h1[0] = h2[0] = h3[0] = h4[0] = 1;
	for(int i = 1;i <= 5000000;i++){
		p1[i] = p1[i - 1] * b1;
		p2[i] = p2[i - 1] * b2;
	}
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s[i] >> t[i];
		int m = s[i].size();
		s[i] = ' ' + s[i],t[i] = ' ' + t[i];
		for(int j = 1;j <= m;j++){
			h1[j] = h1[j - 1] * b1 + s[i][j];
			h2[j] = h2[j - 1] * b2 + s[i][j];
		}
		for(int j = 1;j <= m;j++){
			h3[j] = h3[j - 1] * b1 + t[i][j];
			h4[j] = h4[j - 1] * b2 + t[i][j];
		}
		mp[(h1[m] + h2[m]) ^ (h1[m] * h2[m])] = (h3[m] + h4[m]) ^ (h3[m] * h4[m]);
	}
	for(int i = 1;i <= m;i++){
		cin >> x >> y;
		int m = x.size(),st = 0,en = 0;
		x = ' ' + x,y = ' ' + y;
		for(int j = 1;j <= m;j++){
			h1[j] = h1[j - 1] * b1 + x[j];
			h2[j] = h2[j - 1] * b2 + x[j];
			if(!st && x[j] != y[j]){
				st = j;
			}
			if(x[j] != y[j]){
				en = j;
			}
		}
		for(int j = 1;j <= m;j++){
			h3[j] = h3[j - 1] * b1 + y[j];
			h4[j] = h4[j - 1] * b2 + y[j];
		}
		int ans = 0;
		for(int j = 1;j <= st;j++){
			for(int k = en;k <= m;k++){
				ull num1 = q1(j,k);
				ull num2 = q2(j,k);
				if(mp[num1] == num2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
