#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[107];
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int l = a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==l){
			l = n*m-i+1;
			break;
		}
	}
	int lie,hang;
	if(l%n!=0)lie = l/n+1;
	else lie = l/n;
	if(lie%2==0)hang = n-l%n+1;
	else if(lie%2!=0&&l%n==0)hang = n;
	else hang = l%n;
	cout << lie << " " << hang;
	
	return 0;
}
