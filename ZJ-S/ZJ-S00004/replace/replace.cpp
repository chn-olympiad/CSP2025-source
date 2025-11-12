#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 9;
const int P = 1331;
const int N = 5e6 + 50;
string s1[N],s2[N];
vector<int> h1[N],h2[N],ht1,ht2;
int p[N],n,q;
int gethash(vector<int> &h,int l,int r){
	if(l > r)return 0;
	return ((h[r] - h[l - 1] * p[r - l + 1]) % MOD + MOD ) % MOD;
}
int check(string &s1,vector<int>& h1,string &s2,vector<int> &h2,
string& t1,vector<int>& ht1,string& t2,vector<int>& ht2){
	int l1 = s1.size() - 1;
	int l2 = t1.size() - 1;
	for(int i = 1;i + l1 - 1 <= l2;i ++){
		if(gethash(h1,1,l1) == gethash(ht1,i,i + l1 - 1)){
			if(gethash(h2,1,l1) == gethash(ht2,i,i + l1 - 1)){
				if(gethash(ht1,1,i - 1) == gethash(ht2,1,i - 1)){
					if(gethash(ht1,i + l1,l2) == gethash(ht2,i + l1,l2)){
						return true;
					}
				}
			}
		}
	}
	return false;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	p[0] = 1;
	for(int i = 1;i <= 5000000;i ++){
		p[i] = p[i - 1] * P % MOD;
	}
	cin >> n >> q;
	for(int i = 1;i <= n;i ++){
		cin >> s1[i] >> s2[i];
		int l = s1[i].size();
		s1[i] = " " + s1[i];
		s2[i] = " " + s2[i];
		h1[i].resize(s1[i].size() + 2);
		h2[i].resize(s2[i].size() + 2);
		for(int j = 1;j <= l;j ++){
			h1[i][j] = h1[i][j - 1] * P + (s1[i][j] - 'a' + 1);
			h2[i][j] = h2[i][j - 1] * P + (s2[i][j] - 'a' + 1);
		}
	}
//	cout << check(s1[1],h1[1],s2[1],h2[1],s1[1],h1[1],s2[1],h2[1]) << endl;
	while(q --){
		string t1,t2;
		cin >> t1 >> t2; 
		if(t1.size() != t2.size()){
			cout << 0 << endl;
			continue;
		}
		int l = t1.size();
		t1 = " " + t1;
		t2 = " " + t2;
		ht1.resize(l + 2);
		ht2.resize(l + 2);
		for(int i = 1;i <= l;i ++){
			ht1[i] = ht1[i - 1] * P + (t1[i] - 'a' + 1);
			ht2[i] = ht2[i - 1] * P + (t2[i] - 'a' + 1);
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			int res = check(s1[i],h1[i],s2[i],h2[i],t1,ht1,t2,ht2);
//			if(res){
//				cout << "find : " << i << endl;
//			}
			ans += res;
			
		}
		cout << ans << endl;
	}
	return 0;
}
