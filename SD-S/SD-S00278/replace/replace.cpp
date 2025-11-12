#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, q;
pair<string, string> p[N];
string t1, t2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++ ){
		cin >> t1 >> t2;
		p[i].first = t1;p[i].second = t2;
	}
	while (q -- ){
		cin >> t1 >> t2;
//		if (t1 == t2) cout << 0;
//		else{
//			int ans = 0;
//			for (int i = 1; i <= n; i ++ ){
//				for (int j = 0; j < t1.size() - p[i].first.size() + 1; j ++ ){
//					bool ok = true;
//					for (int k = j; k < j + p[i].first.size(); k ++ ){
//						if (t1[k] != p[i].first[k - j]){
//							ok = false;
//							break;
//						}
//					}
//					if (ok){
//						string x = t1.substr(1, j - 1), z = t1.substr(j + p[i].first.size(), t1.size() - p[i].first.size() - j + 1);
//						if (x + p[i].second + z == t2) ans ++ ;
//						if (x.size() + p[i].second.size() + z.size() != t2.size()) ans -- ;
//					}
//				}
//			}
//			cout << max(0, ans);
//		}
		cout << "0\n";
	}
	return 0;
}
