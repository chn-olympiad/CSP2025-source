#include<iostream>
using namespace std;
int th=1,n,m,r,c=1,d=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>r){
			th++;
		}
	}
	while(th>n){
		th-=n;
		c++;
	}
	if(c%2==1){
		d=th;
	}else{
		d=n-th+1;
	}
	cout<<c<<" "<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
