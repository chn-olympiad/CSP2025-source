#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
struct info{
	string x,y;
	ll xb,yb;
	ll l;
}a[200005];
ll ma,mi;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	string x = "123456";
//	string y = x.substr(1,4);
//	cout << y;
	cin >> n >> q;
	for(ll i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y;
		a[i].l = (a[i].x).size();
	}
	while(q--){
		string x,y;
		cin >> x >> y;
		ll len = x.size();
		ma = -1000000000,mi = 100000000000;
		if(len != y.size()){
			printf("0\n");
			continue;
		}
		for(ll i = 0;i < len;i++){
			if(x[i] != y[i]){
				mi = min(mi,i);
				ma = max(ma,i);
			}
		}
		ll ans = 0;
		for(ll i = 1;i <= n;i++){
			for(ll j = 0;j+a[i].l-1 <= len;j++){
				//string z = x;
				if(!(ma < 0 || (ma >= j && ma <= j+a[i].l-1 && mi >= j && mi <= j+a[i].l-1))){
					continue;
				}
				string w = x.substr(j,j+a[i].l-1-j+1);
			//	cout << "w:" << w << '\n';
				if(w == a[i].x){
			//		cout << x.substr(0,j) << ' ' << a[i].y << ' ' <<x.substr(j+a[i].l,len-1-(j+a[i].l)+1) << '\n';
					string z = x.substr(0,j) + a[i].y + x.substr(j+a[i].l,len-1-(j+a[i].l)+1);
				//	bool flag = 1;
					
				//	cout << "z:" << z << '\n';
				//	cout << "y:" << y << '\n';
					if(z == y){
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/

