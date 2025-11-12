#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 10;
int n, m;
int a[3];
int b[M];
int b2[M];
int c[3] = {0};
int l = 0, k, cnt = 0;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		cnt = 0;
		c[0] = 0, c[1] = 0, c[2] = 0;
		for(int j = 0; j < m; j++){
			cin >> a[0] >> a[1] >> a[2];
			if(a[0] >= a[1] && a[0] >= a[2]){
				b[l] = a[0];
				b2[l] = a[0] - max(a[1], a[2]);
				sort(b2, b2 + l);
				c[0]++, l++;
				if(c[0] > m / 2){
					cnt -= b2[0];
					b2[0] = M;
					c[0]--;
				}
			} else if(a[1] >= a[0] && a[1] >= a[2]){
				b[l] = a[1];
				b2[l] = a[1] - max(a[0], a[2]);
				sort(b2, b2 + l);
				c[1]++, l++;
				if(c[1] > m / 2){
					cnt -= b2[0];
					b2[0] = M;
					c[1]--;
				}
			} else{
				b[l] = a[2];
				b2[l] = a[2] - max(a[1], a[0]);
				sort(b2, b2 + l);
				c[2]++, l++;
				if(c[2] > m / 2){
					cnt -= b2[0];
					b2[0] = M;
					c[2]--;
				}
			}
			cnt += b[l-1];
		}
		cout << cnt << endl;
	} 
	return 0;
}
