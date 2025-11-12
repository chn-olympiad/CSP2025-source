#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005],u,v;
int n,m,k,q,l,r,ans;
bool flag;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i]; 
	}
	while(q--){
		cin >> u >> v;
		ans = 0;
		m = u.size();
		if(m == v.size()){
			l = r = -1;
			for(int i = 0;i <= m;i++){
				if(u[i] != v[i]){
					if(l == -1){
						l = i;
					}
					r = i;
				}
			}
			for(int i = 1;i <= n;i++){
				k = a[i].size();
				if(k >= r - l + 1){
					for(int x = max(0,r - k + 1);x <= min(l,m - k);x++){
						flag = 1;
						for(int y = x;y < x + k;y++){
							if(a[i][y - x] != u[y] || b[i][y - x] != v[y]){
								flag = 0;
								break;
							}
						}
						if(flag){
							ans++;
							break;
						}
					} 
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
