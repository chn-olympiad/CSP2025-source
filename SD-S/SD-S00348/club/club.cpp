#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5+3;
struct node{
	int id,now,c;
	bool operator > (const node& a) const {return c > a.c;}
};
int a[N][4],n;
int now[N][4],cnt[4],ans;
priority_queue<node,vector<node>,greater<node> >  q[4];
int check(){
	for (int i = 1;i <= 3;i++){
		if (cnt[i] > n/2)  return i;
	}
	return 0;
}
int read(){
	int num = 0;
	char c = getchar();
	while ('0' <= c&&c <= '9'){
		num = num*10+(c-'0');
		c = getchar();
	}
	return num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	T = read();
	while (T--){
		ans = 0;
		for (int i = 1;i <= 3;i++){
			while (!q[i].empty())  q[i].pop();
		}
		for (int j = 1;j <= 3;j++)  cnt[j] = 0;
		n = read();
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= 3;j++){
				a[i][j] = read();
			}
		}
		for (int i = 1;i <= n;i++){
			int mx = 0,mn = 0;
			for (int j = 1;j <= 3;j++){
				if (a[i][j] >= mx){
					mx = a[i][j]; mn = j;
				}
			}
			now[++cnt[mn]][mn] = i;
			ans += a[i][mn];
			for (int j = 1,f = 0;j <= 3;j++){
				if (j == mn)  continue;
				if (!f){
					f = a[i][mn]-a[i][j];
				}
				else{
					q[mn].push({i,mn,min(f,a[i][mn]-a[i][j])}); 
				}
			}
		}
		int k = check();
		while (k != 0){
//			cout<<n<<'\n';
//			cout<<k<<' '<<cnt[k]<<'\n';
			node u = q[k].top();
			q[k].pop();
			int i = u.id;
			int nxt = u.now%3+1,nxtt = nxt%3+1;
			cnt[k]--;
			if (a[i][k] >= a[i][nxt]&&a[i][k] >= a[i][nxtt]){
				if (a[i][nxt] > a[i][nxtt]){
					q[nxt].push({i,nxt,a[i][nxt]-a[i][nxtt]});
					ans -= a[i][k]-a[i][nxt];
					cnt[nxt]++;
				}
				else{
					q[nxtt].push({i,nxtt,a[i][nxtt]-a[i][nxt]});
					ans -= a[i][k]-a[i][nxtt];
					cnt[nxtt]++;
				}
			}
			else{
				if (a[i][k] >= a[i][nxt]){
					ans -= a[i][k]-a[i][nxt];
					cnt[nxt]++;
				}
				else if (a[i][k] >= a[i][nxtt]){
					ans -= a[i][k]-a[i][nxtt];
					cnt[nxtt]++;
				}
			}
			k = check();
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
