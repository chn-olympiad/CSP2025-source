#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;

struct Node {
	ll data;
	ll k[4];
};

struct Node_2 {
	ll x;
	ll y;
};

bool cmp_2(Node_2 x,Node_2 y) {
	return x.x > y.x;
}

bool cmp_3(Node_2 x,Node_2 y) {
	return x.y > y.y;
}

Node f[maxn + 100][4];
Node_2 b[maxn + 100];
int a[maxn + 100][4];
int t;
int n;
bool check;
bool check_2;
ll AAns;

void init() {
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= 3;j ++) f[i][j] = {0,{0,0,0,0}};
	}
}

void dfs(ll I,ll x,ll y,ll z,ll Ans) {
	if(I > n) {
		AAns = max(Ans,AAns);
		return ; 
	}
	
	for(int i = 1;i <= 3;i ++) {
		if(i == 1) {
			if(x + 1 <= n / 2) {
				dfs(I + 1,x + 1,y,z,Ans + a[I][i]);
			}
		}else if(i == 2) {
			if(y + 1 <= n / 2) {
				dfs(I + 1,x,y + 1,z,Ans + a[I][i]);
			}
		}else {
			if(z + 1 <= n / 2) {
				dfs(I + 1,x,y,z + 1,Ans + a[I][i]);
			}
		}
	}
	
}

void dfs2(ll I,ll x,ll y,ll Ans) {
	if(I > n) {
		AAns = max(Ans,AAns);
		return ; 
	}
	
	for(int i = 1;i <= 2;i ++) {
		if(i == 1) {
			if(x + 1 <= n / 2) {
				dfs2(I + 1,x + 1,y,Ans + a[I][i]);
			}
		} {
			if(y + 1 <= n / 2) {
				dfs2(I + 1,x,y + 1,Ans + a[I][i]);
			}
		}
	}
	
}

int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
//	freopen("club4.in","r",stdin);
//	freopen("club4.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> t;
	while(t --) {
		cin >> n;
		
		if(n == 2) {
			ll Ans = 0;
			int x,y,z,xx,yy,zz;
			cin >> x >> y >> z >> xx >> yy >> zz;
			Ans = max(max(max(x + yy,x + zz),max(y + xx,y + zz)),max(z + xx,z + yy));
			cout << Ans << '\n';
			continue;
		}
		
		
		init();
		check = check_2 = true;
		
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= 3;j ++) {
				cin >> a[i][j];
				if(a[i][2] != 0 || a[i][3] != 0) check = false;
				if(a[i][3] != 0) check_2 = false;
			}
		}
		
		if(check) {
			ll sum[n + 1];
			for(int i = 1;i <= n;i ++) {
				sum[i] = a[i][1];
			}
			sort(sum + 1,sum + 1 + n);
			ll Ans = 0;
			for(int i = n;i >= n / 2;i --) Ans += sum[i];
			cout << Ans << '\n';
			continue;
		}
		
		if(check_2) {
			ll Ans_1 = 0,Ans_2 = 0;
			for(int i = 1;i <= n;i ++) {
				b[i].x = a[i][1];
				b[i].y = a[i][2];
			}
			sort(b + 1,b + 1 + n,cmp_2);
		
			for(int i = 1;i <= n;i ++) {
				if(i <= n / 2) Ans_1 += b[i].x;
				else Ans_1 += b[i].y;
			}	
		
			sort(b + 1,b + 1 + n,cmp_3);
			for(int i = 1;i <= n;i ++) {
				if(i <= n / 2) Ans_2 += b[i].y;
				else Ans_2 += b[i].x;
			}
			
			cout << max(Ans_1,Ans_2) << '\n';
			continue;

		}
		
		if(n <= 10) {
			AAns = 0;
			dfs(1,0,0,0,0);
			cout << AAns << '\n';
			continue;
		}
		
		f[1][1] = {a[1][1],{0,1,0,0}};
		f[1][2] = {a[1][2],{0,0,1,0}};
		f[1][3] = {a[1][3],{0,0,0,1}};
		
		for(int i = 2;i <= n;i ++) {
		//	for(int o = i - 1;o >= 1;o --) {
				for(int j = 1;j <= 3;j ++) {
					Node cnt = f[i][j];
					for(int l = 1;l <= 3;l ++) {
						if(f[i - 1][l].k[j] + 1 <= n / 2) {//还能继续再加 
							if(cnt.data < f[i - 1][l].data + a[i][j]) {//结果更优 
								cnt = f[i - 1][l];
								cnt.data += a[i][j];
								cnt.k[j] ++;
							}
						}
					}
				//	cerr << cnt.data << '\n';
					f[i][j] = cnt;
				}				
		//	}

		}
		
		ll ans = 0;
		for(int i = 1;i <= 3;i ++) ans = max(ans,f[n][i].data);
		
		cout << ans << '\n';
	}
	
	
	return 0;
} 
/*

18：28
要结束了吗 
我尽力了... ，真的累了 

*/
