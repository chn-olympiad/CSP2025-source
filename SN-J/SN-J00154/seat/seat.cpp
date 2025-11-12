#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l,ha,la,b=1;
	cin>>h>>l;
	int a[l][h];
	for(int i=0;i<l;i++){
		for(int j=0;j<h;j++){
			cin>>a[i][j];
			if(a[i][j]>a[0][0])b++;
		}
	}
	la=(b-b%h)/h+1;
	if(la%2==1){
		ha=b%h;
		if(ha==0){
			ha=h;
		}
	}else{
		ha=h-b%h+1;
	}
	cout<<la<<" "<<ha;
	return 0;
}
