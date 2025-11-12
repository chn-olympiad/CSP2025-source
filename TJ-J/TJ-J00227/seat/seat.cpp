#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10005],shu,c,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	shu=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==shu){
			c=i;
		}
	}
	
	if(c/n % 2 == 0){
		cout << 1+n-c%n;
	}
	else{
		cout << c%n;
	}
	cout << ' ';
	if(c/n==0){
		cout << c/n;
	}
	else{
		for(int i=c;;i++){
			if(i%n==0){
				cout << i/n;
				break;
			}
		}
	}
	return 0;
}
