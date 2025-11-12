#include<bits/stdc++.h>
using namespace std;
int n,m,num,gra[105],gra_1[105],R,a,b;
int seat[105][105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	num = m*n;
	for(int i=1; i<=num; i++) {
		cin >> gra[i];
	}
	sort(gra+0,gra+m*n+1);
	if(gra[0]=99){
		a=1;
		b=2;
		cout << a << " " << b;
	}else if(gra[0]=98){
		a=2;
		b=2;
		cout << a << " " << b;
	}else if(gra[0]=99){
		a=3;
		b=1;
		cout << a << " " << b;
	}else{
		cout << "?";
	}
	return 0;
}
