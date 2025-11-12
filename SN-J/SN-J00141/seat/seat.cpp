//SN-J00141 刘益铭 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;

const int N = 20;

int n,m,p;

pair<int,int> a[N*N];

bool cmp(pair<int,int> x,pair<int,int> y) {
	return x.first > y.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i<=n*m;i++) {
		if(a[i].second == 1) {
			p = i;
			break;
		}
	}
	cout << ceil((double)p / n) << ' ';
	if((int)ceil((double)p / n) % 2 == 0) {
		if(p % n == 0) cout << 1;
		else cout << n - p % n + 1;
	}else {
		if(p % n == 0) cout << n;
		else cout << p % n;
	}
	return 0;
}
