#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,a[10003],x[10003];
//	for(int i=0;i<10003;i++){
//		cin>>a[i];
//	}
	for(int i=0;i<a[10003];i++){
		for(int j=0;j<9;j++){
			if(a[i]==j){
				for(int l=0;l<x[10003];l++){
					x[l]=a[i];
				}
				break;
			}
		}
		
	}
	sort(x[10003]);
	for(int i=0;i<x[10003];i++){
		cout<<a[i];
	}
	return 0;
}
