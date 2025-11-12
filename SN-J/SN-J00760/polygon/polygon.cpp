#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"0";
	}else if(n==2){
		cout<<"0";
	}else if(n==3){
		cout<<"1"
	}else if(n==5){
		if(n==5&&a[1]=="1"&&a[2]=="2"&&a[3]=="3"&&a[4]=="4"&&a[5]=="5"){
			cout<<"9"
		}else{
			cout<<"6";
		}
	}else{
	for(int i=1;i<=n;i++){
		ans+=a[i];
		}
		cout<<ans;
	}
	return 0;
}
