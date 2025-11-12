#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
struct node{
	int a , b , c;
	int id , cha;
};
bool cmp(node xx , node yy){
	return xx.cha < yy.cha;
}
node x[N];
signed main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
// ¶à²âÇå¿Õ 
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int ans = 0;
		for(int i=1;i<=n;i++){
			cin >> x[i].a >> x[i].b >> x[i].c;
			if(x[i].a >= x[i].b && x[i].a >= x[i].c){
				x[i].id = 1;
				x[i].cha = x[i].a - max(x[i].b , x[i].c);
			}
			else if(x[i].b >= x[i].a && x[i].b >= x[i].c){
				x[i].id = 2;
				x[i].cha = x[i].b - max(x[i].a , x[i].c);
			}
			else if(x[i].c >= x[i].b && x[i].c >= x[i].a){
				x[i].id = 3;
				x[i].cha = x[i].c - max(x[i].b , x[i].a);
			}
		}
		int cnta = 0 , cntb = 0 , cntc = 0;
		for(int i=1;i<=n;i++){
			if(x[i].id == 1){
				cnta++;
				ans += x[i].a;
			}
			else if(x[i].id == 2){
				cntb++;
				ans += x[i].b;
			}
			else if(x[i].id == 3){
				cntc++;
				ans += x[i].c;
			}
		}
		sort(x + 1 , x + n + 1 , cmp);
		if(cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2){
			cout << ans << endl;
		}
		else if(cnta > n / 2){
			for(int i=1;i<=n;i++){
				if(x[i].id == 1){
					ans -= x[i].cha;
					cnta--;
				}
				if(cnta == n / 2){
					break;
				}
			}
			cout << ans << endl;
		}
		else if(cntb > n / 2){
			for(int i=1;i<=n;i++){
				if(x[i].id == 2){
					ans -= x[i].cha;
					cntb--;
				}
				if(cntb == n / 2){
					break;
				}
			}
			cout << ans << endl;
		}
		else if(cntc > n / 2){
			for(int i=1;i<=n;i++){
				if(x[i].id == 3){
					ans -= x[i].cha;
					cntc--;
				}
				if(cntc == n / 2){
					break;
				}
			}
			cout << ans << endl;
		}
		for(int i=1;i<=n;i++){
			x[i].a = x[i].b = x[i].c = x[i].cha = x[i].id = 0;
		}
	}
}
