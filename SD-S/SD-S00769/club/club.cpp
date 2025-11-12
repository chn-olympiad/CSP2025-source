#include <bits/stdc++.h>
#define PB push_back
#define ll long long
//#define int long long

using namespace std;

void rd(int &x){
	int flag = 1; x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= flag;
}

const int N = 1e5 + 5; 

struct node{
	int v, num;
};
node a[N][4];

struct node2{
	int Mx, Mn, C;
}cj[N];

bool cmp(node x, node y){
	if(x.v == y.v) return x.num < y.num;
	return x.v > y.v;
}
bool cmp2(node2 x, node2 y){
	return x.C > y.C;
}

int lc[4][N];
int cnt[5];

signed main(){

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	rd(T);
	while(T --){
		int n;
		rd(n);
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= 3; j ++){
				rd(a[i][j].v);
				a[i][j].num = j;
			}
			sort(a[i] + 1, a[i] + 4, cmp);
		}	
		
		for(int i = 0; i <= 3; i ++) cnt[i] = 0;
		for(int i = 1; i <= n; i ++){
			int nc = a[i][1].num;
			lc[nc][++ cnt[nc]] = i;
		}
		int kc = 0;
		for(int i = 1; i <= 3; i ++){
			if(cnt[i] > (n / 2)) kc = i;  
		}
		ll ans = 0;
		if(!kc){
			for(int i = 1; i <= n; i ++){
				ans += a[i][1].v;
			}
			cout << ans << '\n';
		}else{
			for(int i = 1; i <= 3; i ++){
				if(i != kc){
					for(int j = 1; j <= cnt[i]; j ++){
						ans += a[lc[i][j]][1].v;
					}
				}
			}
			for(int i = 1; i <= cnt[kc]; i ++){
				cj[i].Mx = a[lc[kc][i]][1].v;
				cj[i].Mn = a[lc[kc][i]][2].v;
				cj[i].C = cj[i].Mx - cj[i].Mn;
			}
			sort(cj + 1, cj + 1 + cnt[kc], cmp2);
			for(int i = 1; i <= (n / 2); i ++){
				ans += cj[i].Mx;
			}
			for(int i = (n / 2) + 1; i <= cnt[kc]; i ++){
				ans += cj[i].Mn;
			}
			cout << ans << '\n';
		}
	}
	
		
	return 0;
}

