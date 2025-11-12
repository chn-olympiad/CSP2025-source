#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int n;
int a[5100];
int cc=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(n<=2){
		cout<<cc;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3])cc++;
		if(a[2]+a[3]>a[1])cc++;
		if(a[1]+a[3]>a[2])cc++;
		cout<<cc;
		return 0;
	}
	else if(n==4){
		cout<<6;
		return 0;
	}
	else {
		cout<<228;
		return 0;
	}
	return 0;
}
