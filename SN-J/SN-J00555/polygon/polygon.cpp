#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0,a[5005]={0},m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]>a[2]){
		if(a[1]>a[3]){
			m=a[1];
		}
		else{
			m=a[3];
		}
	}
	else{
		if(a[2]>a[3]){
			m=a[2];
		}
		else{
			m=a[3];
		}
	}
	if(a[1]+a[2]+a[3]>m*2){
		num++;
	}
	cout<<num;
	return 0;
}
