#include<bits/stdc++.h>
using namespace std;

int a[110] = {0};
bool cmp(int x, int y){
	return x > y;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) cin >> a[i];
	int f = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i <= n*m; i++)
		if(a[i]==f) f=i;
	int c = (f-1)/n+1, r = (f-1)%n+1;
	if(c%2) cout << c << " " << r;
	else cout << c << " " << (n-r+1);
	return 0;
}
