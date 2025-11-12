#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, top, up;
string S1[N], S2[N];
string req;
map<string, int> lk;
map<pair<int, int>, int> exist;
vector<pair<int, int> > fb[N];
int f[N], ft, b[N], bt;
map<int, bool> ff, bb;
#define int long long
void specA(){
	while(q--){
		int Ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())puts("0");
		else{
			int l = 0, r = t1.size() - 1;
			while(t1[l] == t2[l])l++;
			while(t1[r] == t2[r])r--;
			string T1 = t1.substr(l, r - l + 1);
			string T2 = t2.substr(l, r - l + 1);
			ft = bt = 0;
			string F, B;
			ff[lk[F]] = bb[lk[B]] = true;
			for(int i = l - 1; i >= 0; i--){
				F = F + t1[i];
				f[++ft] = lk[F];
				ff[f[ft]] = true;
			}
			for(int i = r + 1; i < t1.size(); i++){
				B = B + t1[i];
				b[++bt] = lk[B];
				bb[b[bt]] = true;
			}
			for(auto c : fb[exist[{lk[T1], lk[T2]}]]){
				if(ff[c.first] && bb[c.second])Ans++;
			}
			for(int i = 1; i <= ft; i++)ff[f[i]] = false;
			for(int i = 1; i <= bt; i++)bb[b[i]] = false;
			cout << Ans << endl;
		} 
	}
}
void init(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		S1[i] = s1, S2[i] = s2;
		if(s1 == s2)continue; 
		int l = 0, r = s1.size() - 1;
		while(s1[l] == s2[l])l++;
		while(s1[r] == s2[r])r--;
		string x = s1.substr(0, l);
		reverse(x.begin(), x.end());
		string z = s1.substr(r + 1, s1.size() - r);
		string a2 = s1.substr(l, r - l + 1);
		string b2 = s2.substr(l, r - l + 1);
		if(!lk[x])lk[x] = ++top;
		if(!lk[z])lk[z] = ++top;
		if(!lk[a2])lk[a2] = ++top;
		if(!lk[b2])lk[b2] = ++top;
		if(!exist[{lk[a2], lk[b2]}])exist[{lk[a2], lk[b2]}] = ++up;
		fb[exist[{lk[a2], lk[b2]}]].push_back({lk[x], lk[z]});
	}
	return void();
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	specA();
	return 0;
}