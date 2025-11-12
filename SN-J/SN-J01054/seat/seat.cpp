#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10005],x,y,c,r,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		x=a[1];
	}
	sort(a,a+(n*m)+1);
	for(int i=n*m;i>=0;i--){
		if(a[i]==x){
			y=n*m-i+1;
		}
	}
	if(y%n==0){
		c=y/n;
		if(c/2==0){
			r=m;
		}
		else{
			r=1;
		}
	}
	else{
		c=y/n+1;
		h=y%n;
		if(c%2==0){
			r=m-h+1;
		}
		else{
			r=h;
		}
	}
	cout<<c<<" "<<r;
		
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
