#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[15][15],x,num=1,y1,x1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	} 
	x=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>x){
				num++;
			}
		}
	} 
	if(m==1){
		cout<<1<<num;
		return 0;
	}
	if(n==1){
		cout<<num<<" "<<1;
		return 0;
	}
	if(num%n==0){
		y1=num/n;
	} else{
		y1=num/n+1;
	}
	if(y1%2!=0){
		if(num%n==0){
			x1=m;
		}else{
			x1=num%n;
		}
	}else{
		x1=n-num%n+1;
	}
	cout<<y1<<" "<<x1;
	return 0;
}
