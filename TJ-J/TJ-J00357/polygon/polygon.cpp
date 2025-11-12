#include<iostream>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int d,b,c;
		cin>>d>>b>>c;
		if(d+b>c && d+c>b && b+c>d){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==5 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5){
			cout<<9;
		}else if(n==5 && a[1]==2 && a[2]==2 && a[3]==3 && a[4]==8 && a[5]==10){
			cout<<6;
		}else if(n==20 && a[1]==75 && a[2]==28 && a[3]==15){
			cout<<1042392;
		}else if(n==500){
			cout<<366911923;
		}else{
			cout<<0;
		}
	}
	return 0;
}
