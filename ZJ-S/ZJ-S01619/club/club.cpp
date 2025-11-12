#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;
ll n, cnt[3], a[maxn][3], mxnum[maxn], lower[maxn], cutt[maxn], tail;
ll ans;
void chk(int x) {
	int mx=-1, scd = -1;
	for(int i = 0; i < 3;i ++) {
		if(mx==-1||a[x][i]>a[x][mx]) {
			scd = mx;
			mx = i;
		} else if(scd==-1||a[x][i]>a[x][scd]) {
			scd = i;
		}
	}
	cnt[mx]++;
	mxnum[x] = mx;
	lower[x] = a[x][scd]-a[x][mx];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--) {
		cin>>n;
		cnt[0]=cnt[1]=cnt[2]=0; ans=0; tail=0;
		for(int i = 1; i <= n; i++) {
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			chk(i);
			ans+=a[i][mxnum[i]];
		}
//		cout<<"1stans:"<<ans<<endl;
		for(int i = 0; i < 3; i++) {
			if(cnt[i]>n/2) {
				for(int j = 1; j <= n; j++) {
					if(mxnum[j]==i) {
						cutt[++tail]=lower[j];
					}
				}
				sort(cutt+1, cutt+tail+1);
//				for(int j = 1; j <= tail; j++) {
//					cout<<cutt[j]<<' ';
//				} cout<<endl;
				for(int j = tail; tail-j+1<=cnt[i]-n/2; j--) {
					ans+=cutt[j];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
