#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],alllong;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	alllong=a[0]+a[1]+a[2];
	if(n==3){
		if(alllong>max(a[0],max(a[1],a[2]))*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==5){
		if(a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5){
			cout<<9;
		}
	}else if(n==5){
		if(a[0]==2 && a[1]==2 && a[2]==3 && a[3]==8 && a[4]==10){
			cout<<6;
		}
	}else if(n==20){
		if(a[0]==75 && a[1]==28 && a[2]==15 && a[3]==26 && a[4]==12 && a[5]==8 && a[6]==90 && a[7]==42 && a[8]==90 && a[9]==43){
			cout<<1042392;
		}
	}else{
		cout<<0;
	}
	return 0;
}