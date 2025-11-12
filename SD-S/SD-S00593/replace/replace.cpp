#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+100;
int n,q;
string s1[N],s2[N],q1,q2;
map<string,string> mp;
int dfs(string s){
	if(s==q2) return 1;
	string pres="";
	int res=0;
	for(int i=0;i<s.size();i++){
		string ts="";
		for(int j=i;j<s.size();j++){
			ts=ts+s[j];
			if(mp[ts]!=""){
				string eds=pres+mp[ts];
				for(int k=j+1;k<s.size();k++){
					eds=eds+s[k];
				}
				if(eds==q2) res++;
			}
		}
		pres=pres+s[i];
	}
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=0;i<n;i++){
		cin >> s1[i] >> s2[i];
		mp[s1[i]]=s2[i];
	}
	for(int i=0;i<q;i++){
		cin >> q1 >> q2;
		cout << dfs(q1) << endl;
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
*/
