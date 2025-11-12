//dzzfjldyqqwsxdhrdhcyxll
#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
const int MAXN = 4e5 + 10;
string a[MAXN],b[MAXN],p[MAXN],q[MAXN];
int n,Q,f[MAXN],len[MAXN],g,t,cnt; 
vector <int> v[MAXN];
map <int,int> mp;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> b[i]; 
		len[i] = a[i].length();
		t += 2 * len[i];
		for(int j = 0;j < len[i];j++) {
			if(a[i][j] != b[i][j]) {
				f[i] = j;
				break;
			}
		}
	}
	for(int i = 1;i <= Q;i++) {
		cin >> p[i] >> q[i];
		g += p[i].length() + q[i].length();
	}
	if(n <= 1000 && g <= 2000 && t <= 2000) {
		for(int i = 1;i <= Q;i++) {
			string s,t;
			s = p[i],t = q[i];
			int pos = 0,l = s.length(),pos1 = 0;
			if(s.length() != t.length()) {
				cout << 0 << endl;
				continue;
			}
			for(int i = 0;i < l;i++) {
				if(s[i] != t[i]) {
					pos = i;
					break;
				}
			}
			for(int i = l - 1;i >= 0;i--) {
				if(s[i] != t[i]) {
					pos1 = i;
					break;
				}
			}
			int ans = 0;
			for(int i = 1;i <= n;i++) {
				if(pos - f[i] < 0) continue;
				bool flag = 1;
				if(pos - f[i] + len[i] - 1 >= l) continue;
				for(int j = 0;j < len[i];j++) {
					flag &= (a[i][j] == s[pos - f[i] + j]);
					flag &= (b[i][j] == t[pos - f[i] + j]);
				}
				flag &= (pos - f[i] + len[i] - 1 >= pos1);
				ans += flag;
	 		}
	 		cout << ans << endl;
		}	
	} else {
		for(int i = 1;i <= n;i++) {
			int pos1 = 0,pos2 = 0;
			for(int j = 0;j < len[i];j++) {
				if(a[i][j] == 'b') pos1 = j;
				if(b[i][j] == 'b') pos2 = j;
			}
			if(!mp[pos1 - pos2]) {
				mp[pos1 - pos2] = ++cnt;
			}
			v[mp[pos1 - pos2]].emplace_back(pos1);
		}
		for(int i = 1;i <= cnt;i++) {
			sort(v[i].begin(),v[i].end());
		}
		for(int i = 1;i <= Q;i++) {
			string s,t;
			s = p[i],t = q[i];
			int l = s.length();
			if(s.length() != t.length()) {
				cout << 0 << endl;
				continue;
			}
			int pos1 = 0,pos2 = 0;
			for(int j = 0;j < l;j++) {
				if(s[j] == 'b') pos1 = j;
				if(t[j] == 'b') pos2 = j;
			}
			if(mp[pos1 - pos2]) {
				int id = mp[pos1 - pos2];
				int tmp = lower_bound(v[id].begin(),v[id].end(),pos1) - v[id].begin();
//				cout << "id = " << id << " size = " << v[id].size() << endl; 
				cout << v[id].size() - tmp << endl; 
			} else cout << 0 << endl;
		}
	}
	return 0;
}