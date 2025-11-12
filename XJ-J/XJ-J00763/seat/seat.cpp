#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ddd;
	int a[105]={0};
	cin>>n>>m;
	cin>>ddd;
	a[1]=ddd;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n*m;j++){
		for(int k=n*m;k>=2;k--){
			if(a[k]<a[k-1]){	
			}
			if(a[k]>a[k-1]){
				int x;
				x=a[k-1];
				a[k-1]=a[k];
				a[k]=x;
			}
		}
	}
	int y=1,z=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==ddd){
			y=i;
			break;
		}
	}
	z=y/n+1;
	cout<<z<<' ';
	if(z%2==0){
		cout<<n-(y%n); 
	}
	if(z%2==1){
		cout<<y%n; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
