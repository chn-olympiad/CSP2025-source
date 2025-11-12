#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int b[1005][1005];
int ki[10][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int t,h,mo;
		cin >> t >> h >> mo;
		a[t][h] = mo;
		a[h][t] = mo;
	}
	for(int i = 1;i <= k;i++){
		int q;
		cin >> q;
		for(int j = 1;j <= n;j++){
			cin >> ki[i][j];
		}
	}
	int ans = 0;
	
	for(int i = 1;i <= n;i++){
		int idm = 1e9;
		int o,p;
		for(int j = 1;j <= n;j++){
			if(a[i][j] != 0){
				if(idm > a[i][j]){
					idm = a[i][j];
					o = i;
					p = j;	
				}
			}
		}
		if(b[o][p] == 1 || b[p][o] == 1){
			continue;
		}else{
			b[o][p]++;
			b[p][o]++;
			ans+=idm;
		}
	}
	for(int i = 1;i <= n;i++){
		int c;
		for(int j = 1;j <= n;j++){
			if(b[i][j] == 1){
				b[i][j] = 2;
				b[j][i] = 2;
				c++;
				continue;
			}
		}
		if(c == 0){
			int im;
			int oo,pp;
			for(int k = 1;k <= n;k++){
				if(b[1][k] == 0){
					im = (im,b[1][k]);
					oo = 1;
					pp = k;
				}
				if(b[i][k] == 0){
					im = (im,b[i][k]);
					oo = i;
					pp = k;
				}
			}
			b[oo][pp] = 1;
			ans+=im;
		}
	}
	cout << ans;
}

