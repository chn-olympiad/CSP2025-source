#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i = 2;i <= n*m;i++){
		cin>>a[i];
	}
	sort(a+2,a+n*m+1,cmp);
	for(int i = 2;i <= n*m;i++){
		int x,y;
		y = (i-1)/n;
		if((i-1) % n != 0)
			y++;
		if(y % 2 == 1){
			x = (i-1)%n;
			if(x == 0) x = n;
		}
		else if(y % 2 == 0){
			x = (i-1)%n;
			if(x == 0) x = 1;
			else x = n-x+1;
		}
		if(r > a[i]){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
}