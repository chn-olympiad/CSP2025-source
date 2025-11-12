#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000005];int s=0;
	for(long long i=1;i<=1000000;i++){
		cin>>a[i];
		s=i; 
	}
	
	while(s){
		int b=0;
		for(long long i=1;i<=1000000;i++){
		 	if(a[i]<a[i+1]){
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}
		}
		
		s--;	
	}
	for(long long i=1;i<=1000000;i++){
		cout<<a[i];
	}
	return 0;
}
