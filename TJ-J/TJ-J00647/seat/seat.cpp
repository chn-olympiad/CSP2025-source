#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
struct Win{
	int score,id;
	bool R;
}mn[13][13];
int n,m,boo;
int a[169];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
		if(i==1)boo=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=m*n;++i){
		if(x>n){
			++y;
			x=1;
		}
		if(y%2==0){
			if(a[i]==boo){
				cout << y << ' ' << n-x+1; 
				return 0;
			}
		}else{
			if(a[i]==boo){
				cout << y << ' ' << x;
				return 0;
			}
		}
		++x;
	}
	return 0;
}
