#include<bits/stdc++.h>
using namespace std;

int n;
int arr[5005],b[5005];
int level = 0;
int ans;

void search(int l,int r,int cnt) {
	if(l > r) return;
	++level;
	b[level] = l;
	int res = cnt;
	cnt += arr[l];
	if(level >= 3) {
		int maxx = -1;
		for(int i = 1; i <= level; ++i) {
			maxx = max(maxx,arr[b[level]]);
		}
		if(cnt > arr[maxx] * 2) ++ans;
	}
	for(int i = l; i <= r; ++i) {
		search(i + 1,n,cnt);
	}
	b[level] = 0;
	--level;
	return;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n - 2; ++i) {
		search(i,n - 2,0);
	}
	
	cout << ans;
}
