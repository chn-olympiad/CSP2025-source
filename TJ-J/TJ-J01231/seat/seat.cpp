#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	int r = n*m;
	for(int i = 1;i<=r;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=r;i++){
		b[i] = a[i];
	}
	sort(a,a+r,cmp);
	for(int i =1;i<=r;i++){
		if(b[0] ==a[i]){
			int c = i/n+1;
			if(c%2==1){
				cout <<c<<' '<<i%n-1;
			} 
			else cout << c<<' '<<m-i%n+1;
		}
	}
	return 0;
}
