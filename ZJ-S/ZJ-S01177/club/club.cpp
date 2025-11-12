#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 1e5+10;

int n;
ll a[N][4];
ll no1_max[N], no2_max[N];
ll club_cnt[4];
int id_to_club[N];

ll tmp[N]; int m;

void work() {
	for(int i=1; i<=n; i++) a[i][1] = a[i][2] = a[i][3] = 0;
	for(int i=1; i<=n; i++) no1_max[i] = no2_max[i] = id_to_club[i] = 0;
	club_cnt[1] = club_cnt[2] = club_cnt[3] = 0;
	for(int i=1; i<=m; i++) tmp[i] = 0;
	n = 0, m = 0;
	
	n = read();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=3; j++)
			a[i][j] = read();
	
	ll ans = 0;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=3; j++)	
			no1_max[i] = max(no1_max[i], a[i][j]);
		
		for(int j=1; j<=3; j++)
			if(a[i][j] == no1_max[i]) {
				club_cnt[j]++;
				id_to_club[i] = j;
				break;
			}
		
		for(int j=1; j<=3; j++)
			if(j != id_to_club[i]) no2_max[i] = max(no2_max[i], a[i][j]);
			
		ans += no1_max[i];
	}
	
	int maxn_clubcnt = max(max(club_cnt[1], club_cnt[2]), club_cnt[3]), maxn_clubid;
	for(int j=1; j<=3; j++)
		if(club_cnt[j] == maxn_clubcnt) maxn_clubid = j;
	
	if(maxn_clubcnt > n/2) {
		for(int i=1; i<=n; i++)
			if(id_to_club[i] == maxn_clubid)
				tmp[++m] = no1_max[i] - no2_max[i];
				
		sort(tmp+1, tmp+1+m);
		
		for(int i=1; i <= maxn_clubcnt - n/2; i++)
			ans -= tmp[i];
	}
	
	write(ans), putchar('\n');
	
	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T = read();
	while(T--) work();
	
	return 0;
}