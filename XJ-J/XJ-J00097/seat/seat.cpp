#include<bits/stdc++.h>
using namespace std;

int n , m , a[11110] , x , y , a1 , a2 , b[110][110] ;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin >> n >> m ;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	a1=a[1];
	sort(a+1,a+1+n);
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(a[i]<a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n*m;i++)
		if(a[i]==a1)
			a2=i;
	if(a2%n==0){
		y=a2/n;
		if(y%2==0)
			cout << y << " 1";
		else
			cout << y << " "<< n ;
	}
	else{
		y=a2/n+1;
		if(y%2==0){
			cout << y << " " << n-a2%n+1;
		}
		else
			cout << y << " " << a2%n;
	}
	return 0;
}
