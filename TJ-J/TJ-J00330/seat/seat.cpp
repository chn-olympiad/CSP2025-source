#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rank=1,time=1,xunhuan=1;
	cin >> n >> m; 
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(a[i]>a[1])rank++;
	}
	while(time<rank){
		time++;
		if(xunhuan>=1 && xunhuan<n)x++;
		else if(xunhuan==n || xunhuan==2*n)y++;
		else x--;
		xunhuan++;
		if(xunhuan>2*n)xunhuan=1;
	}
	cout << y << " " << x;
	return 0;
}
