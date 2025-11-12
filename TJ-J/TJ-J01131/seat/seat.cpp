#include <bits/stdc++.h>

using namespace std;

int n,m,a[100],c,r,a1,h;

int cmp(int x,int y){
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	a1 = a[1];
	
	sort(a+1,a+(n*m)+1,cmp);
	
	for(int i = 1;i <= n*m;i++){
		if(a[i] == a1) h = i;
	}
	
	c = (h + n - 1) / n;
	if(c%2 == 0){
		r = n + 1 - h%n;
	}else{
		r = h%n;
	}
	
	cout << c << ' ' << r;
	
	return 0;
}


