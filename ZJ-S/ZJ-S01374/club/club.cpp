#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int t,n,a[N][3],cnt[3],d[3][N];
int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t = read();
	while(t --){
		int ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		n = read();
		for(int i=1;i<=n;i++){
			a[i][0] = read(),a[i][1] = read(),a[i][2] = read();
			int mx = max(a[i][0],max(a[i][1],a[i][2]));
			if(mx == a[i][0]){
				cnt[0] ++;
				d[0][cnt[0]] = mx - max(a[i][1],a[i][2]);
			}
			else if(mx == a[i][1]){
				cnt[1] ++;
				d[1][cnt[1]] = mx - max(a[i][0],a[i][2]);
			}
			else{
			    cnt[2] ++;	
			    d[2][cnt[2]] = mx - max(a[i][0],a[i][1]);
			}
			ans += mx;
		}
		int id = -1;
		if(cnt[0] > n/2) id = 0;
		if(cnt[1] > n/2) id = 1;
		if(cnt[2] > n/2) id = 2;
		if(id == -1){
			printf("%lld\n",ans);
			continue;
		}
		sort(d[id]+1,d[id]+cnt[id]+1);
		int idx = 1;
		while(cnt[id] > n/2){
			ans -= d[id][idx];
			++ idx,cnt[id] --;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
