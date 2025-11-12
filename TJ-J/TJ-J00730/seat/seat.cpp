#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,j=1;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	int x=a[1];
	if(n==1){
		if(m==1){
			cout<<"1 1";
		}else{
			sort(a,a+b+1);
			for(int i=m;i>=1;i--){
				if(a[i]==x){
					cout<<j<<" 1";
				}
				j++;
			}
		}
	}
	if(m==1){
		sort(a,a+b+1);
		for(int i=n;i>=1;i--){
			if(a[i]==x){
				cout<<"1 "<<j;
			}
			j++;
		}
	}
	return 0;
} 
