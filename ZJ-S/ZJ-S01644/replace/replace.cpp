#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7;
string s[maxn][2];

int count(string s1, string s2){
	int sum = 0;
	while(s1.find(s2) != -1){
		sum++;
		s1.erase(s1.find(s2), s2.size());
	}
	return sum;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		string s1, s2; cin >> s1 >> s2; int sum = 0;
		for(int i = 1; i <= n; ++i){
			if(s1.find(s[i][0]) != -1){
				if(s[i][0] == s[i][1]){
					sum += count(s1, s[i][0]);
				}else{
					string s3 = s1;
					s3.replace(s1.find(s[i][0]), s[i][0].size(), s[i][1]);
					if(s3 == s2) sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
