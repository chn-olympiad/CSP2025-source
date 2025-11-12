#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull p = 100003;
const int MAXL = 5e6 + 10, N = 2e5 + 10;
ull powp[MAXL], Hash[MAXL], HS1[N], HS2[N];
string s1[N], s2[N], t1, t2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	powp[0] = 1;
	for(int i = 1; i < MAXL; i++) powp[i] = powp[i - 1] * p;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		for(int j = (int)s1[i].size() - 1; j >= 0; j--){
			HS1[i] = HS1[i] * p + s1[i][j] - 'a' + 1;
		}
		for(int j = (int)s2[i].size() - 1; j >= 0; j--){
			HS2[i] = HS2[i] * p + s2[i][j] - 'a' + 1;
		}
	}
	while(q--){
		cin >> t1 >> t2;
		ull HT2 = 0;
		int l1 = (int)t1.size();
		for(int j = (int)t2.size() - 1; j >= 0; j--){
			HT2 = HT2 * p + t2[j] - 'a' + 1;
		}
		Hash[l1] = 0;
		for(int j = l1 - 1; j >= 0; j--){
			Hash[j] = Hash[j + 1] * p + t1[j] - 'a' + 1;
		}
		ll ans = 0;
		for(int i = 0; i < l1; i++){
			for(int j = 1; j <= n; j++){
				int lj = (int)s1[j].size();
				if(i + lj <= l1){
					if(Hash[i] - Hash[i + lj] * powp[lj] == HS1[j]){
						ull H1 = Hash[0] - Hash[i] * powp[i];
						ull H2 = Hash[i + lj];
						if(H1 + HS2[j] * powp[i] + H2 * powp[i + lj] == HT2){
							ans++;
						}
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}