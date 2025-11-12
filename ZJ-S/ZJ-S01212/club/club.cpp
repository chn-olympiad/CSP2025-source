#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n;
struct qus{
	long long int fi, ch;
}qu[5][N];
bool cmp(qus ai, qus bi){
	return ai.ch < bi.ch;
}
int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	while(T){
		scanf("%d", &n);
		int ci, cnt[5];
		long long int ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int t = 0; t < n; t ++){
			int maxs = -1e9, maxt, ses = -1e9;
			for(int y = 0; y < 3; y ++){
				scanf("%d", &ci);
				if(ci > maxs){
					ses = max(maxs, ses);
					maxs = ci;
					maxt = y;
				}
				else if(ci > ses){
					ses = ci;
				}
			}
			qu[maxt][cnt[maxt]] = (qus){maxs, maxs - ses};
			ans += maxs;
			cnt[maxt] ++;
		}
		int bjt = -1;
		for(int t = 0; t < 3; t ++){
			if(cnt[t] > n / 2){
				bjt = t;
			}
		}
		if(bjt == -1){
			printf("%lld\n", ans);
		}
		else{
			sort(qu[bjt], qu[bjt] + cnt[bjt], cmp);
			int jn = 0;
			while(cnt[bjt] > n / 2){
				cnt[bjt] --;
				ans -= qu[bjt][jn].ch;
				jn ++;
			}
			printf("%lld\n", ans);
		}
		/*for(int t = 0; t < cnt[bjt]; t ++){
			qu[0][t].ch = qu[0][t].fi = 0;
			qu[1][t].ch = qu[1][t].fi = 0;
			qu[2][t].ch = qu[2][t].fi = 0;
		}*/
		T --;
	}
	return 0;
}