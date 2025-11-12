#include<bits/stdc++.h>
#define int long long
#define ll unsigned long long
using namespace std;
int n, q, id;
string s1, s2;
map<ll, map<ll, int> > mp;
vector<pair<ll, pair<int, int> > > v[201000];
ll P = 13331, p[5001000], po[5001000];
ll getp(string s){
	ll res = 0;
	for(int i = 0;i < s.size();i++){
		res = res * P + s[i];
	}
	return res;
}
void check(string t1, string t2){
	string res1, res2;
	bool flag = true;
	int l = 0, r = 0;
	for(int i = 0;i < t1.size();i++){
		if(t1[i] != t2[i]){
			l = i;
			break;
		}
	}
	for(int i = t1.size() - 1;i >= l;i--){
		if(t1[i] != t2[i]){
			r = i;
			break;
		}
	}
	for(int i = l;i <= r;i++){
		res1 += t1[i];
		res2 += t2[i];
	}
	int p1 = getp(res1), p2 = getp(res2);
	if(!mp[p1][p2])
		mp[p1][p2] = ++id;
	v[mp[p1][p2]].push_back(make_pair(getp(t1), make_pair(l - 1, t1.size() - r - 1)));
}
int ask(string t1, string t2){
	string res1, res2;
	bool flag = true;
	int l = 0, r = 0;
	for(int i = 0;i < t1.size();i++){
		if(t1[i] != t2[i]){
			l = i;
			break;
		}
	}
	for(int i = t1.size() - 1;i >= l;i--){
		if(t1[i] != t2[i]){
			r = i;
			break;
		}
	}
	for(int i = l;i <= r;i++){
		res1 += t1[i];
		res2 += t2[i];
	}
	po[0] = 1;
	for(int i = 0;i < t1.size();i++){
		po[i + 1] = po[i] * P;
		p[i + 1] = p[i] * P + t1[i];
	}
	int p1 = getp(res1), p2 = getp(res2);
	if(!mp[p1][p2])
		return 0;
	int res = 0;
	for(int i = 0;i < v[mp[p1][p2]].size();i++){
		int lsz = v[mp[p1][p2]][i].second.first;
		int rsz = v[mp[p1][p2]][i].second.second;
		ll hash = v[mp[p1][p2]][i].first;
		if(lsz <= l - 1 && rsz <= t1.size() - r - 1, p[rsz + r + 1] - p[l - lsz - 1] * po[rsz + r + 1 - (l - lsz - 1)] == hash){
			res++;
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1 >> s2;
		check(s1, s2);
	}
	for(int i = 1;i <= q;i++){
		cin >> s1 >> s2;
		cout << ask(s1, s2) << "\n";
	}
	return 0;
}

