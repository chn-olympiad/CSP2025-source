#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
const int N = 2e5 + 5;
string a[N], b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= q; ++i){
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.length() != t2.length()){
			cout << 0 << endl;
			continue;
		}
		int fp = -1, lp = -1;
		for (int i = 0; i < t1.length(); ++i){
			if (t1[i] != t2[i]){
				if (fp == -1){
					fp = i;
				}
				lp = i;
			}
		}
		long long tot = 0;
		for (int i = 1; i <= n; ++i){
			if(t1.find(a[i]) != string::npos){
				int beg = t1.find(a[i]);
				if (beg + a[i].length() - 1 < lp || beg > fp) continue;
				if (t2.find(b[i]) != string::npos){
					int fac = t2.find(b[i]);
					if (fac != beg) continue;
					++tot;
				}
				else continue;
			}
		}
		cout << tot << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

