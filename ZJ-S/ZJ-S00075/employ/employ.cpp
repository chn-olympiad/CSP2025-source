#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510 ,Q = 998244353;
ll n ,m ,ns[N] ,cnt0[N];
char in[N];
ll f[N][N][N]; // dijige qilejige kexuanjige

ll ans1 = 0 ,vis[N];
void dfs(ll idx) {
	if (idx == 0) {
		ll flag = 1;
		ll cnt = 0;
		for (int i=1 ;i<=n ;i++) {
			if (vis[i] == 1) {
				cnt++;
			}
		}
		if (cnt < m) {
			return;
		}
		ll cnt_g = 0; //cnt : give up
		for (int i=1 ;i<=n ;i++) {
			if (in[i] == 0) {
				
			}
		}
		ans1 += flag;
		return;
	}
	vis[idx] = 1;
	dfs(idx-1);
	vis[idx] = 0;
	dfs(idx-1);
}

int main() {
	freopen("employ.in" ,"r" ,stdin);
	freopen("employ.out" ,"w" ,stdout);
	scanf("%lld %lld" ,&n ,&m);
	scanf("%s" ,(in+1));
	for (int i=1 ;i<=n ;i++) {
		scanf("%lld" ,&ns[i]);
		if (ns[i] == 0) {
			cnt0[i] = 1;
		}
	}
	sort(ns+1 ,ns+1+n);
	for (int i=1 ;i<=n ;i++) {
		cnt0[i] += cnt0[i-1];
	}
	ll tmp = 0;
	for (int i=1 ;i<=n ;i++) {
		vis[i] = i;
	}
	do {
		ll cnt = 0;
		for (int i=1 ;i<=n ;i++) {
			if (in[i] == '0' || cnt >= ns[vis[i]]) {
				cnt++;
			}
		}
		if (n - cnt >= m) {
			for (int i=1 ;i<=n ;i++) {
				//out<<vis[i]<<" ";
			}
			//cout<<cnt<<endl;
			//cout<<endl;
			tmp++;
		}
	}while(next_permutation(vis+1 ,vis+1+n));
	printf("%lld" ,tmp);
//	sort(ns+1 ,ns+1+n);
//	for (int i=n ;i>=1 ;i--) {
//		for (int j=0 ;j<=i ;j++) {
//			for (int k=0 ;k<=n ;k++) {
//				ll tmp = lower_bound()
//			}
//		}
//	}
	
	
	return 0;
}
