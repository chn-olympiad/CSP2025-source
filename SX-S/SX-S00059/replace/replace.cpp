#include<bits/stdc++.h>

using namespace std;

int n, q;
pair<string, string> sb[200010];
map<pair<string, string>, int> mp;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++){
		cin>>sb[i].first>>sb[i].second; mp[sb[i]] ++;
	}
	while(q --){
		string t1, t2; cin>>t1>>t2;
		int s = -1, t = -1;
		for(int i = 0; i < (signed)t1.size(); i ++) if(t1[i] != t2[i]){
			if(s == -1) s = i;
			t = i;
		}
		int ans = 0;
		for(int i = 0; i <= s; i ++){
			string f1 = "", f2 = "";
			for(int j = i; j < t; j ++) f1 += t1[j], f2 += t2[j];
			for(int j = t; j < (signed)t1.size(); j ++){
				f1 += t1[j], f2 += t2[j];
				ans += mp[{f1, f2}];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}