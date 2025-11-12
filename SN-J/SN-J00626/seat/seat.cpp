#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int I=n*m;
	int ai;
	cin>>ai;
	a[1]=ai;
	for (int i=2;i<=I;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+I);
	int bianhao;
	int azhong=1+I/2;
	if (a[azhong]>ai){
		for (int i=1;i<=azhong;i++){
			if (a[i]==ai){
				bianhao=i;
				break;
			}
		}
	}else if (a[azhong]<ai){
		for (int i=azhong;i<=I;i++){
			if (a[i]==ai){
				bianhao=i;
				break;
			}
		}
	}else{
		bianhao=azhong;
	}
	
	int x,y;
	int yjian=bianhao%n;
	if (yjian!=0){
		x=bianhao/n+1;
		if (x%2==0){
			y=n-yjian;
		}else{
			y=yjian;
		}
	}else{
		x=bianhao/n;
		if (x%2==0){
			y=1;
		}else{
			y=n;
		}
	}
	
	
	cout<<y<<" "<<x;
	return 0;
}
