#include<bits/stdc++.h>
using namespace std;
string s[200000+100][3];
int n, Q;
int ans = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>Q;
	for(int i = 1; i <= n; i++){
		cin>>s[i][1]>>s[i][2];
	} 
	while(Q--){
		ans = 0;
		string t1, t2;
		cin>>t1>>t2;
		for(int i = 1; i <= n; i++){
			if(t1.find(s[i][1]) <= t1.size()){
				char ts[200];
				int sp = t1.find(s[i][1]);
				int e = sp+s[i][1].size()-1;
				int p = 0;
				for(int j = 0; j < t1.size(); j++){
					if(j >= sp && j <= e) ts[j] = s[i][2][p++];
					else ts[j] = t1[j];
				}
				if(ts == t2) ans++;
			}
			else if(t1.find(s[i][2]) <= t1.size()){
				char ts[200];
				int sp = t1.find(s[i][2]);
				int e = sp+s[i][2].size()-1;
				int p = 0;
				for(int j = 0; j < t1.size(); j++){
					if(j >= sp && j <= e) ts[j] = s[i][1][p++];
					else ts[j] = t1[j];
				}
				if(ts == t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

