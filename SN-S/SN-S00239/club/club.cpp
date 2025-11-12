#include "bits/stdc++.h"
using namespace std;
const int N= 1e5+5;

int t, n;
int ans;

struct Node{
	int a, b, c;
}g[N];

bool cmp1(Node x, Node y){
	if(x.a != y.a) return x.a > y.a;
	else if(x.b != y.b) return x.b > y.b;
	else return x.c >= y.c;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin>>t;
	while(t--){
		cin >> n;
		int hn = n/2;
		bool flag = 0;
		for(int i=1;i<=n;++i){
			cin >> g[i].a >> g[i].b >> g[i].c;
		}
		
		int cnt = 0, sg = 1;
		ans = 0;
		
		if(n == 2){
			ans = max(ans, g[1].a + g[2].b);
			ans = max(ans, g[1].a + g[2].c);
			ans = max(ans, g[1].b + g[2].a);
			ans = max(ans, g[1].b + g[2].c);
			ans = max(ans, g[1].c + g[2].a);
			ans = max(ans, g[1].c + g[2].b);
			cout << ans << endl;
			continue;
		}
	
		sort(g+1, g+n+1, cmp1);
		for(int i=1;i<=n;++i){
			cnt++;
			if(sg == 1){
				if(g[i].b > g[i].a) {
					cnt = 1;
					sg++;
					ans+=g[i].b;
				}else ans+= g[i].a;
			}else if(sg == 2){
				if(g[i].c > g[i].b) {
					cnt = 1;
					sg++;
					ans+=g[i].c;
				}else ans+= g[i].b;
			}else ans+=g[i].c;
			if(cnt >= hn){
				sg++;
				cnt = 0;
			}
			
		}
		cout << ans << endl;
			
	}
	
	return 0;
}
