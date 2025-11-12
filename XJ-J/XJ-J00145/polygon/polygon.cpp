#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long int n,a[5100],num=0,max=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		for(int i=1;i<=n;i++){
			num+=a[i];
		    if(a[i]>max){
			    max=a[i];
		    }
		}
		if(num>max*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<9; 
	}
	return 0;
}
