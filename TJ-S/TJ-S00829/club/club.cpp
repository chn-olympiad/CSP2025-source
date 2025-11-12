#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+10;
int T, n;
int cnt[4];

ll ans = 0;
struct node {
	ll v; int id;
}a[N][5], b[N][5], tmp[4];

struct node1 {
	ll first; int second;
}Q[4][N];

bool cmp(node1 x, node1 y) {
	return x.first < y.first;
}
bool cmp1(node x, node y) {
	return x.v > y.v;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--) {
        cin >> n;
        cnt[1] = cnt[2] = cnt[3] = 0;
        for(int i=1; i<=n; i++) {
            cin >> tmp[1].v >> tmp[2].v >> tmp[3].v; tmp[1].id = 1, tmp[2].id = 2, tmp[3].id = 3;
            b[i][1].v = tmp[1].v; b[i][2].v = tmp[2].v; b[i][3].v = tmp[3].v;
        	sort(tmp+1, tmp+4, cmp1);
            a[i][1] = tmp[1]; a[i][2] = tmp[2]; a[i][3] = tmp[3];
            Q[a[i][1].id][++cnt[a[i][1].id]] = {a[i][1].v-a[i][2].v, a[i][2].v};
            //cout << a[i][1].id << " ";
        }
        //cout << "\n";
        ans = 0;
        for(int i=1; i<=n; i++) {
        	ans += a[i][1].v;
        	//cout << a[i][1].v << " " << ans << "\n";
    	}
        
        while(cnt[1] > (n/2)) {
        	//cout << 1;
            sort(Q[1]+1, Q[1]+cnt[1]+1, cmp);
            //for(int i=1; i<=cnt[1]-n/2; i++) cout << Q[1][i].first << " ";
            for(int i=1; i<=cnt[1]-n/2; i++) ans -= Q[1][i].first;
            break;
        }
        while(cnt[2] > (n/2)) {
            sort(Q[2]+1, Q[2]+cnt[2]+1, cmp);
            for(int i=1; i<=cnt[2]-n/2; i++) ans -= Q[2][i].first;
            break;
        }
        while(cnt[3] > (n/2)) {
            sort(Q[3]+1, Q[3]+cnt[3]+1, cmp);
            for(int i=1; i<=cnt[3]-n/2; i++) ans -= Q[3][i].first;
            break;
        }
//        while(!Q[1].empty()) {cout << b[Q[1].top().second][1].v << " "; Q[1].pop();}
//        cout << "\n";
//        while(!Q[2].empty()) {cout << b[Q[2].top().second][2].v << " "; Q[2].pop();}
//        cout << "\n";
//        while(!Q[3].empty()) {cout << b[Q[3].top().second][3].v << " "; Q[3].pop();}
//        cout << "\n";
		//cout << "\n";
        cout << ans << "\n";
    }

	return 0;
}



