#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0,i=0,s=0,c=0,m=0;
	cin>>n;
	int a[n+5]={0};
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	else{
		for(i=0;i<n;i++){
			s+=a[i];
			if(a[i]>m){
				m=a[i];
			}
		}
		if((2*m)<s){
			cout<<1;
		}
		else{
			cout<<0;
	    }
	}
	return 0;
}
