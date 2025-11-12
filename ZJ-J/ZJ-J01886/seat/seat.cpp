#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,ans;
int a[110];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) cin >> a[i];
	int cnt = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++){
		if(a[i] == cnt) ans = i;
	} 
	if(ans % n == 0) c = ans / n;
	else c = ans / n + 1;
	if(c % 2 == 1) r = n - (n * c - ans);
	else r = n - (ans - n * (c - 1)) + 1;
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
