#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",)
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]=x){
			cout<<i/m<<i%n;
		}
	}
	return 0;
} 
