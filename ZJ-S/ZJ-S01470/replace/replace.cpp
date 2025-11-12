#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e5+5,Q = 2e5+5,L = 5e6+5;
int n,q;
string ss1[N],ss2[N],tt1[N],tt2[N];
map<string,map<string,int> > mp;
pair<string,string> strr(string s1,string s2){
	int l = -1,r = 0;
	for (int i = 0;i < s1.size();i++){
		if (s1[i] == s2[i]) continue;
		if (l == -1) l = i;
		r = i;
	}
	if (l == -1) return make_pair("","");
	return make_pair(s1.substr(l,r-l+1),s2.substr(l,r-l+1));
}
void sub1(){
	for (int j = 1;j <= n;j++){
		string s1 = ss1[j],s2 = ss2[j];
		pair<string,string> s34 = strr(s1,s2);
		string s3 = s34.first,s4 = s34.second;
		for (int l = 0;l < s3.size();l++)
			for (int len = 1;l+len-1 < s3.size();len++) mp[s3.substr(l,len)][s4.substr(l,len)]++;
	}
	for (int j = 1;j <= q;j++){
		string t1 = tt1[j],t2 = tt2[j];
		pair<string,string> s34 = strr(t1,t2);
		string s3 = s34.first,s4 = s34.second;
		cout << mp[s3][s4] << '\n';
	}
}
void sub2(){
	sub1();
}
void subb(){
	bool bbb = 1;
	for (int i = 1;i <= n;i++){
		cin >> ss1[i] >> ss2[i];
		int sb = 0;
		if (bbb == 0) continue;
		for (int j = 0;j < ss1[i].size();j++){
			if (ss2[i][j] == 'b') sb++;
			else if (ss1[i][j] != 'a') bbb = 0;
		}
		if (sb != 1) bbb = 0;
	} 
	for (int i = 1;i <= q;i++){
		cin >> tt1[i] >> tt2[i];
		int sb = 0;
		if (bbb == 0) continue;
		for (int j = 0;j < tt1[i].size();j++){
			if (tt2[i][j] == 'b') sb++;
			else if (tt1[i][j] != 'a') bbb = 0;
		}
		if (sb != 1) bbb = 0;
	} 
	if (q == 1){
		sub2();
		return;
	}
	if (bbb == 0){
		sub1();
		return;
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	subb();
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
