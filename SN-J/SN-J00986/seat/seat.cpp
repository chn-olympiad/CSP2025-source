#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[101],d;
main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+1+n*m);
	int j=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==b){
			d=j;
			break;
		}
		j++;
	}
	if(d%n==0&&d/n%2==1){
		c=d/n;
		r=n;
		cout<<c<<" "<<r;
	}else if(d%n==0&&d/n%2==0){
		c=d/n;
		r=1;
		cout<<c<<" "<<r;
	}else if(d/n%2==1){
		r=d-d/n*n;
		r=n-r+1;
		c=d/n+1;
		cout<<c<<" "<<r;
	}else{
		r=d-d/n*n;
		c=d/n+1;
		cout<<c<<" "<<r;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
