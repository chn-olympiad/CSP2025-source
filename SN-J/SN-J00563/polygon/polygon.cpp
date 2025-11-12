#include<bits/stdc++.h>
using namespace std;
int n,maxx,num=0,num1=0;
int a[5001]={0};
void dg(int b){
	if(num1>maxx){
		num=(num+1)%998244353;
	}
	if(b==1){
		return;
	}
	for(int i=b;i>=1;i--){
		num1+=a[i];
		dg(i);
		num1-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n<3)cout<<"0";
		else{
			if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
				cout<<"1";
			}else{
				cout<<"0";
			}	
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int maxx=a[i]*2;
		num1=a[i];
		dg(i);
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
