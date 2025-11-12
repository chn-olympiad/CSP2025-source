#include <bits/stdc++.h>
using namespace std;

int sc[155];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int sum = n * m;
	cin >> sc[1];
	int rs = sc[1];
	for(int i = 2; i <= sum; i++) cin >> sc[i];
	sort(sc+1, sc+sum+1, cmp);
	int cnt = 1, f, fi;
	for(int j = 1; j <= m; j++){
		if(j % 2 == 0){
			f = -1;
			fi = n;
		}else{
			f = 1;
			fi = 1;
		}
		for(int i = fi; i <= n && i >= 1; i+=f){
			if(sc[cnt] == rs){
				cout << j << ' ' << i;
				return 0;
			}
			cnt++;
		}
	}
	
	return 0;
}
