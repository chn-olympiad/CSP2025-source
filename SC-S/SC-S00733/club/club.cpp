#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+20;
int T,n,cnt[3],belong[N];ll a[N][3],ans;
priority_queue<ll>P;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;++i){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
				ans += a[i][0];cnt[0]++;belong[i] = 0;
			}else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
				ans += a[i][1];cnt[1]++;belong[i] = 1;
			}else{
				ans += a[i][2];cnt[2]++;belong[i] = 2;
			}
		}if(cnt[0] > n/2 || cnt[1] > n/2 || cnt[2] > n/2){
			while(!P.empty()) P.pop();
			if(cnt[0] > n/2){
				for(int i = 1;i <= n;++i){
					if(belong[i] == 0){
						P.emplace(-a[i][0]+max(a[i][1],a[i][2]));
					}
				}while(cnt[0] > n/2){
					ans += P.top();P.pop();cnt[0]--;
				}
			}else if(cnt[1] > n/2){
				for(int i = 1;i <= n;++i){
					if(belong[i] == 1){
						P.emplace(-a[i][1]+max(a[i][0],a[i][2]));
					}
				}while(cnt[1] > n/2){
					ans += P.top();P.pop();cnt[1]--;
				}
			}else{
				for(int i = 1;i <= n;++i){
					if(belong[i] == 2){
						P.emplace(-a[i][2]+max(a[i][0],a[i][1]));
					}
				}while(cnt[2] > n/2){
					ans += P.top();P.pop();cnt[2]--;
				}
			}
		}cout << ans << "\n";ans = 0;cnt[0] = cnt[1] = cnt[2] = 0;
	}
	return 0;
}