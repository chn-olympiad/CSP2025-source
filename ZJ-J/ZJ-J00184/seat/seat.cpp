#include<iostream>
using namespace std;
int n,m,a,ma=1,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a;
	for(int i=1;i<=n*m-1;i++){
		cin >> x;
		if(x>a) ma++;
	}
	int y=(ma-1)/n+1;
	if(y%2==1){
		cout << y << " " << ma-(y-1)*n;
	}else{
		cout << y << " " << m-ma+(y-1)*n+1;
	}
	return 0;
}
