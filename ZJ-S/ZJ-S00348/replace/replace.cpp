#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define OPEN freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
string a[N],b[N],x,y;
int n,q;
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	OPEN
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
	while(q--){
		cin >> x >> y;
		int dif = 0,f = 1;
		for(int i = 0;i < x.size();i++){
			if(x[i] != y[i] && f) dif++;
			if(x[i] == y[i] && dif) f = 0;
			if(x[i] != y[i] && !f){
				dif = -1;
				break;
			}
		}
		if(dif == -1){
			cout << "0\n";
			continue;
		}
		int ans = 0;
		if(dif == 0) ans++;
		for(int i = 1;i <= n;i++){
			if(a[i].size() < dif) continue;
			for(int j = 0;j < x.size();j++){	
				string p = "";
				for(int k = j;k < j + a[i].size();k++) p += x[k];
				if(p == a[i]){
					string z = x;
					int o = 0;
					for(int k = j;k < j + a[i].size();k++) z[k] = b[i][o++];
					if(z == y) ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
