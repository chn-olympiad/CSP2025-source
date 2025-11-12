#include<bits/stdc++.h>
#define F(i,l,r) for(int i(l); i <= (r); ++ i)
#define G(i,r,l) for(int i(r); i >= (l); -- i)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
//#define int ll
using namespace std;
using ll = long long;
const int N = 2e6;
char s[N], r[N], t[N], c[N], k[N];
int n, m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	F(i, 1, n){
		cin >> s + 1;
		cin >> r + 1;
	}
	while(m --){
		int ans = 0;
		cin >> (t + 1) >> (c + 1);
		int l = strlen(t + 1);
		F(i, 1, n){
			int len = strlen(s + 1);
			F(j, 1, l) k[j] = t[j];
			F(j, 1, n - len + 1){
				int flag = 1;
				F(p, j, j + len - 1){
					if(s[p] != k[p]){
						flag = 0;
						break;
					} 
				}
				if(flag){
					F(p, j, j + len - 1){
						k[p] = s[p];
					}
					int ff = 1;
					F(j, 1, l){
						if(k[j] != c[j]){
							ff = 0;
							break;
						}
					}
					if(ff) ++ ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return fflush(0), 0;
}