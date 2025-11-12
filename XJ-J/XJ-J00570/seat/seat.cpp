#include <bits/stdc++.h>
using namespace std;
int cmd(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, a[15], s, n, o;
	bool down_stand=false;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	s = a[1];
	if(n==1){
		if(m==1){
			 cout<<1<<" "<<1;
		} else if(m==2){
			cout<<1<<" "<<2;
		}
	}
	if(n==2){
		if(m==1){
			cout<<a[n];
		}
		if(m==2){
			cout<<a[n];
		}
	}
	o = lower_bound(a+1, a+n+1, s, cmd)-a;
	cout<<o/n<<char(32)<<o%n;
	return 0;           
}							                                                                        
