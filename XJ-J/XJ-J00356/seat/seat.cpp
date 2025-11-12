#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N], n, m, t, id, r, c;
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	int R=a[1];
	t=n*m;
	sort(a+1,a+1+t,cmp);
	for(int i=1; i<=t; i++){
		if(R==a[i]) id=i;
	}
	c=ceil(id*1.0/n);
	r=id%n;
	if(c%2!=0){
		if(r==0) r=n;
	}
	else{
		if(r==0) r=1;
		else r=n-r+1;
	}
	cout <<  c << ' ' << r;
	return 0;
}
