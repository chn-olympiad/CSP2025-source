#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int a[101];
	int s[11][11]={0};
	int r, c, y=0;
	for(int i=1; i<=(n*m); i++){
		cin >> a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a, a+(m*n)+1);
	for(int i=1; i<=(n*m); i++){
		if (a[i]==r){
			c=(m*n+1)-i;
		}	
	}
	while(c>=n){
		c-=n;
		y++;
	}
	if (c==0){
		cout << y << " ";
	}else{
		cout << ++y << " ";
	}
	if (m%2==0){
		if (y%2==0){
			cout << c+1 << endl;
		}else{
			cout << m-c << endl;
		}
	}else{
		if (y%2==0){
			cout << c+1 << endl;
		}else{
			cout << m-c-1 << endl;
		}
	}
	return 0;
}
