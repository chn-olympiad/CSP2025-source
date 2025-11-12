#include<bits\stdc++.h>
using namespace std;
int n,m,c,r,x,s,k;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+(n*m));
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			s=n*m-i;
		}
	}
	if(s%n>0){
		c=s/n+1;
		k=s%n;
		if(c%2==1){
			r=k;
		}
		else{
			r=n-k+1;
		}
	}
	else{
		c=s/n;
		if(c%2==1){
			r=n;
		}
		else r=1;
	}
	cout<<c<<" "<<r;
	return 0;
}
