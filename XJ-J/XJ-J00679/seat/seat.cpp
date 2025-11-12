#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10005];
	int n,m,i,j,t,a1,c,r;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		a1=a[1];
	}
	for(i=1;i<=n*m;i++){
		for(j=i;j<=n*m;j++){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=1;i<=n*m;i++){
		if(a[i]==a1){
			if(i%n==0){
				c=i/n;
				if(c%2==0){
					r=1;
					break;
				}
				else{
					r=n;
					break;
				}
			}
			else{
				c=i/n+1;
				if(c%2==0){
					r=n*c+1-i;
					break;
				}
				else{
					r=i-(c-1)*n;
					break;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
