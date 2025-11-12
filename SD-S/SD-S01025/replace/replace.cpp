#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string a,b;
}s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string g,h;
		cin >> g >> h;
		s[i].a = g;
		s[i].b = h;
	}
	while(q--){
		string g,h;
		cin >> g >> h;
		if(g.size() != h.size()){
			cout << 0 << endl;
			continue;
		}
		int k = -1,kk = 0;
		for(int i = 0;i <= g.size();i++){
			if(g[i] != h[i]){
				kk = i;
				if(k == -1)k = i;
			}
		}
		int ans = 0;
		for(int j = 1;j <= n;j++){
			int viss = 0;
			string da = s[j].a;
			string dd = s[j].b;
			if(da.size() < kk-k+1) continue;
			int wy = da.size(),hwy = g.size();
			for(int o = max(kk-wy+1,0);o <= min(k,hwy-wy+1);o++){
				if(g[o] == da[0]){
					int vis = 1;
					for(int p = o;p <= o+da.size()-1;p++){
						if(g[p] != da[p-o] || h[p] != dd[p-o]){
							vis = 0;
							break;
						}	
					}
					if(vis){
						viss = 1;
						break;
					}
				}
			}
			if(viss) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}


