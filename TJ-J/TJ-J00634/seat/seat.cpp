#include<bits/stdc++.h>
using namespace std;
int a[1091];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int d = 1;
	int u;
	cin >> u;
	for(int i = 2;i<=n*m;i++){
		cin >> a[i];
		if(a[i]>u) d++;
	}
	int ans1 = d/n+1;
	if(d%n==0) ans1--;
	int ans2 = d%n;
	if(ans2==0) ans2 = n;
	if(ans1%2==0) ans2 = n+1-ans2;
	cout << ans1 << ' ' << ans2;
	return 0;
} 
