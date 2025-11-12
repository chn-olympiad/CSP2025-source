#include <bits/stdc++.h>
using namespace std;
int t,n,x;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int cnt = 0;
	cin >> t >> n >> x;
	int a[n],b[n],c[n];
	for (int i = 0;i<n;i++){
		cin >> a[n]>> b[n]>> c[n];
	}
	sort(c,c+n);
	for (int i = 0;i<t-1;i++){
			cnt+=c[i];
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}