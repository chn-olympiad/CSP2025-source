#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <string>

using namespace std;
const int N = 10010;


unordered_map<string,string> p;
int n,q;
string g[N];




int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		string a,b;
		cin >> a >> b;
		p[a] = b;
		g[i] = a;
	}
	while(q--) {
		int ans = 0;
		string start,end;
		cin >> start >> end;
		int len1 = start.length(),len2 = end.length();
		for(int j = 1 ; j <= n ; j++) {
			for(int i = 0 ; i + (int)g[j].length() <= len1 ;i ++)
			{
				if(g[j][0]!=start[i]) continue;
				string t = start.substr(0,i);
				t+= p[g[j]];
				t+=  start.substr(i+(int)g[j].length());
				if(t==end) ans++;
			}
		}
		cout << ans << '\n';
	}


	return 0;
}
