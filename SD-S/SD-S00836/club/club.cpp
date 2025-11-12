#include<bits/stdc++.h>
using namespace std;
int t,n,m,sum[5],ans;
struct club{
	int a[5],nmax,nmin,num;
}u[100005];
bool cmp(club x,club y){
	return x.a[x.nmax] - x.a[x.num] > y.a[y.nmax] - y.a[y.num];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int j = 1;j <= t;j++){
		cin >> n;
		ans = sum[1] = sum[2] = sum[3] = 0;
		for(int i = 1;i <= n;i++){
			cin >> u[i].a[1] >> u[i].a[2] >> u[i].a[3];
			if(max(u[i].a[1],max(u[i].a[2],u[i].a[3])) == u[i].a[1]){
				u[i].nmax = 1;
			}else if(max(u[i].a[1],max(u[i].a[2],u[i].a[3])) == u[i].a[2]){
				u[i].nmax = 2;
			}else{
				u[i].nmax = 3;
			}
			if(min(u[i].a[1],min(u[i].a[2],u[i].a[3])) == u[i].a[3]){
				u[i].nmin = 3;
			}else if(min(u[i].a[1],min(u[i].a[2],u[i].a[3])) == u[i].a[2]){
				u[i].nmin = 2;
			}else{
				u[i].nmin = 1;
			}
			u[i].num = 6 - u[i].nmax - u[i].nmin;
		}
		sort(u + 1,u + n + 1,cmp);
		for(int i = 1;i <= n;i++){
			if(sum[u[i].nmax] * 2 >= n){
				sum[u[i].num]++;
				ans += u[i].a[u[i].num];
			}else{
				sum[u[i].nmax]++;
				ans += u[i].a[u[i].nmax];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
