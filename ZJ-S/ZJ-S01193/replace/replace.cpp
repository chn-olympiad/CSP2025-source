#include<bits/stdc++.h>
using namespace std;
int n, q;
string s1, s2;
map<string, map<string, int> > mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		mp[s1][s2]++;
	}
	for(; q--; ){
		cin >> s1 >> s2;
		if(s1.size() != s2.size()){
			printf("0\n");
			continue;
		}
		int m = s1.size();
		int ll = m, rr = 0;
		for(int i = 0; i < m; i++){
			if(s1[i] != s2[i]){
				ll = min(ll, i);
				rr = max(rr, i);
			}
		}
		long long ans = 0;
		string str1, str2, t = "#";
		for(int i = 0; i <= ll; i++){
			str1 = str2 = "";
			for(int j = i; j < rr; j++){
				t[0] = s1[j];
				str1 += t;
				t[0] = s2[j];
				str2 += t;
			}
			for(int j = rr; j < m; j++){
				t[0] = s1[j];
				str1 += t;
				t[0] = s2[j];
				str2 += t;
				ans += mp[str1][str2];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
