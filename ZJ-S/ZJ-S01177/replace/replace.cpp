#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 2e5+10;
const int M = 5e6+10;

string s[N][2];
int len[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n = read(), q = read();
	for(int i=1; i<=n; i++)
		cin>>s[i][0]>>s[i][1],
		len[i] = s[i][0].length(),
		s[i][0] = " " + s[i][0], s[i][1] = " " + s[i][1];
	
	while(q--) {
		string a,b; cin>>a>>b;
		int l1 = a.length(), l2 = b.length();
		a = " " + a, b = " " + b;
		
		if(1ll*a.length() * n > 1e7 or l1 != l2) {
			printf("0\n");
			continue ;
		}
		
		int lid, rid;
		
		for(int i=1; i<=l1; i++)
			if(a[i] != b[i]) {
				lid = i;
				break;
			}
			
		for(int i=l1; i>=1; i--)
			if(a[i] != b[i]) {
				rid = i;
				break;
			}
		
		int ans = 0;
		for(int l=lid; l>=1; l--)
			for(int r=rid; r<=l1; r++) {
				for(int i=1; i<=n; i++) {
					if(len[i] != (r-l+1)) continue ;
					
					bool res = 1;
					int id2 = 1;
					for(int id=l; id<=r; id++,id2++)
						if(a[id] != s[i][0][id2] or b[id] != s[i][1][id2]) {
							res = 0;
							break;
						}
					
					if(res) ans++;
				}
			}
			
		write(ans), putchar('\n');
	}
	
	return 0;
}