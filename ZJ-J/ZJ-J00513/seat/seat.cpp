#include <bits/stdc++.h>
using namespace std;
int n, m, a[200], k, p;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i ++)cin >> a[i];
	k = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i ++)if(k == a[i])p = i;
	int t = (p-1)/n;
	if(t % 2 == 0){
		cout << t + 1 << ' ' << p - n * t; 
	}else {
		cout << t + 1 << ' ' << m - p + n * t + 1;
	}
	return 0;
}
