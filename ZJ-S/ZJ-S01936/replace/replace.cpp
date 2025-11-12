#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<string> ve1[200010];
vector<string> ve2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s1,s2;
		cin >> s1 >> s2;
		ve1[i].push_back(s1);
		ve2[i].push_back(s2);
	}
	while(q--){
		string s3,s4;
		cin >> s3 >> s4;
		int cnt = 0;

		for(int i = 1; i <= n; i++){
			string s5 = ve1[i][0];
			string s6 = ve2[i][0];
			for(int j = 0; j <= s3.size()-1;j++){
				if(s3.substr(j,j+s5.size()) == s5 && s4.substr(j,j+s6.size()) == s6){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
