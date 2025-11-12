#include<bits/stdc++.h>
using namespace std;
int a[105];
int r = 1,c = 1;
int ca,ra;
bool cmp(int a,int b){
	return a >= b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int cnt = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[1] == cnt){
			cout << 1  << ' ' << 1;
			return 0;
		}
		int sum = 1;
		if(c % 2 == 1){
			r++;
			sum++;
			if(r == n){
				c += 1;
				r = n;
				sum++;
			}
		}
		if(c % 2 == 0){
			r--;
			sum++;
			if(r == 1){
				c += 1;
				r = 1;
				sum++;
			}
		}
		if(c > m || r > n){
			continue;
		}
		int ans = sum - ((c-1) * n);
		if(a[i] == cnt){
			if((c - 1) * n + ans == i){
				ca = c,ra = r;
			}
		}
	}
	cout << ca << ' ' << ra;
	return 0;
}
