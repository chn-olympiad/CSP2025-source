#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[110],ac,order;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int st=n*m;
	for(int i=1;i<=st;i++)cin >> a[i];
	ac=a[1];
	sort(a+1,a+1+st);
	for(int i=1;i<=st;i++){
		if(a[i]==ac){
			order=st-i+1;
			break;
		}
	}
	int lie;
	if(order%n)lie=order/n+1;
	else lie=order/n;
	cout << lie << " "; 
	if(lie%2){
		if(order%m)cout << order%m;
		else cout << n;
	}
	else{
		if(order%m)cout << n-order%m+1;
		else cout << 1;
	}
	return 0;
}
