#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for(int i = j; i <= k; i++)
#define int long long
#define MaxN 205

int n, q;
string a[MaxN], b[MaxN];

signed main()
{
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out","w", stdout);
	cin >> n >> q;
	For(i, 1, n){
		cin >> a[i] >> b[i];
	}
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		s1 = '!' + s1; s2 = '!' + s2;
		int ans = 0;
		For(l, 1, len){
			For(num, 1, n){
				string s = s1;
				int flag = 0, p = 0;
				while(s[l+p] == a[num][l+p]) p++;
				if(p-l == a[num].size()){
					For(j, l, l+p-1){
						s[j] = b[num][j];
					}
				}
				if(s == s2) ans++;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
