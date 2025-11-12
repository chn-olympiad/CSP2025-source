//100
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
struct person{
	ll a[4];
	ll m;
}d[N];
person x,y;
int p,p1,p2;
bool cmp1(int b,int c){
	x = d[b];
	y = d[c];
	return max(x.a[p1],x.a[p2]) < max(y.a[p1],y.a[p2]);
}
//bool cmp2(person x,person y){
//	return x.a[x.m]-x.a[2] > y.a[y.m]-y.a[2];
//}
//bool cmp3(person x,person y){
//	return x.a[x.m]-x.a[3] > y.a[y.m]-y.a[3];
//}
int cnt[4];
int data[4][N];
int T;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		ll ans = 0;
		for(int i = 1;i <= 3;i++) cnt[i] = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> d[i].a[1] >> d[i].a[2] >> d[i].a[3];
			ll maxx = 0;
			int p = 0;
			for(int j = 1;j <= 3;j++){
				if(maxx < d[i].a[j]){
					maxx = d[i].a[j];
					p = j;
				}
			}
//			cout << i << " "<< maxx << " " << p << '\n';
			d[i].m = p;
			data[p][++cnt[p]] = i;
			ans += maxx;
		}
		int maxx = 0;
		for(int i = 1;i <= 3;i++) maxx = max(maxx,cnt[i]);
//		cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << '\n';
		if(maxx <= n/2){
			cout << ans << '\n';
			continue;
		}
		p1 = 0;
		p2 = 0;
		for(int i = 1;i <= 3;i++){
			if(maxx == cnt[i]) p = i;
			else{
				if(p1) p2 = i;
				else p1 = i;
			}
		}
//		cout << p << " " << p1 << " " << p2 << '\n';
		for(int i = 1;i <= cnt[p];i++){
			int pp = data[p][i];
			int ap = d[pp].a[p];
//			cout << pp << " " << ap << " " << d[pp].a[p1] << " " << d[pp].a[p2] << '\n';
			d[pp].a[p1] -= ap;
			d[pp].a[p2] -= ap;
			
		}
		sort(data[p]+1,data[p]+cnt[p]+1,cmp1);
		for(int i = cnt[p];i > n/2;i--){
			person x = d[data[p][i]];
//			cout << min(x.a[p]-x.a[p1],x.a[p]-x.a[p2]) << '\n';
			ans += max(x.a[p1],x.a[p2]);
		}
		cout << ans << '\n';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

