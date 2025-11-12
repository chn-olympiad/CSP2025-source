#include<bits/stdc++.h>
using namespace std;
int t,n,a[100009],b[100009],c[100009],x[100009][9],ans,l[100009],tot;
int ma(int x,int y,int z){
	if(x >= y && x >= z){
		return 1;
	}
	if(y >= x && y >= z){
		return 2;
	}
	return 3;
}
vector <int> v[5];//i和j混用调了30min，现在大样例过 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> x[i][1] >> x[i][2] >> x[i][3];
			a[i] = ma(x[i][1],x[i][2],x[i][3]);
			b[i] = ma(a[i] == 1 ? 0 : x[i][1],a[i] == 2 ? 0 : x[i][2],a[i] == 3 ? 0 : x[i][3]);
			c[i] = x[i][a[i]] - x[i][b[i]];
			v[a[i]].push_back(i);
			ans += x[i][a[i]];
//			cout << a[i] << ' ' << b[i] << '\n';
		}
//		cout << ans << '\n';
		for(int i = 1;i <= 3;i++){
			if((int)v[i].size() > (n >> 1)){
				for(int u : v[i]){
					l[++tot] = c[u];
//					cout << l[tot] << ' ';
				}
				sort(l + 1,l + tot + 1);
//				cout << '\n';
				for(int j = 1;j <= (int)v[i].size() - n / 2;j++){
					ans -= l[j];
//					cout << ans << ' ';
				}
				break;
			}
		}
		cout << ans << '\n';
		v[1].clear();v[2].clear();v[3].clear();
		ans = tot = 0;
	}
	return 0;
}
