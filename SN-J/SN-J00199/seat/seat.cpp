//SN-J00199  吴禹泽  陕西延安中学
#include<iostream>
#include<algorithm>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, m, score;
int a[105];
int c, r;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	fastio;
	
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	score = a[1];
	
	sort(a+1, a+n*m+1, cmp);
	
	int id;
	for(int i=1; i<=n*m; i++) {  
		if(a[i] == score) {
			id = i;
			break;
		}
	}
	
	c = (id - 1) / n + 1;
	if(c & 1) r = (id - 1) % n + 1;
	else r = n - (id - 1) % n;
	cout<<c<<' '<<r;
	return 0;
}
