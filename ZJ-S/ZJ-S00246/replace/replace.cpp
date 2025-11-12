#include<bits/stdc++.h>
using namespace std;

int n,q;
map<string,string> s;

int dfs(string t1,string t2){
	int ans = 0;
	if(t1 == t2) ans++;
	for(int i = 0;i < t1.length();i++){
		for(auto _ : s){
			if(i + _.first.length() >= t1.length()) continue;
			bool flag = true;
			for(int j = 0;j < _.first.length();j++){
				if(_.first[j] != t1[i + j]){
					flag = false;
					break;
				}
			}
			string t = t1;
			if(flag){
				for(int j = 0;j < _.first.length();j++){
					t[i + j] = _.first[j];
				}
			}
			ans += dfs(t,t2);
		}
	}
	return ans;
}

int main(){
	ifstream cin("replace.in");
	ofstream cout("replace.out");
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		string a,b;
		cin>>a>>b;
		s[a] = b;
	}
	for(int i = 1;i <= q;i++){
		string t1,t2;
		cin>>t1>>t2;
		cout<<dfs(t1,t2)<<"\n";
	}
	return 0;
}
/////////////////////////////////
