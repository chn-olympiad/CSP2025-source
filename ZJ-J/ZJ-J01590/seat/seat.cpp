#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[110],r,rs;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			rs=i;
			break;
		}
	}
	if(rs%n){
		cout<<rs/n+1<<' ';
		if(rs/n%2){
			cout<<n-rs%n+1;
		}
		else{
			cout<<rs%n;
		}
	}
	else{
		cout<<rs/n<<' ';
		if(rs/n%2){
			cout<<n;
		}
		else{
			cout<<1;
		}
	}
	return 0;
}
