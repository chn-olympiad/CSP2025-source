#include<bits/stdc++.h>
using namespace std;

int n, m, a[101], ansx, ansy, now;

bool cmp(const int lhs, const int rhs){
	return rhs < lhs;
}

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);	
	cin >> n >> m;
	int lenth = m * n;
	for(int i = 1;i <= lenth;i++)cin >> a[i];
	int k = a[1], t;
	sort(a + 1, a + lenth + 1, cmp);
	for(int i = 1;i <= lenth;i++){
		if(a[i] == k){
			t = i;
			break;
		}
	}
	for(int i = 1;i <= n;i++){
		if(i % 2 == 0){
			for(int j = m;j >= 1;j--){
				now++;
				if(t == now)cout << i << " " << j;
			}
		}
		else{
			for(int j = 1;j <= m;j++){
				now++;
				if(t == now)cout << i << " " << j;
			}
		}
	}
	return 0;
}
