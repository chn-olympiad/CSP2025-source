#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,c,r,d,j=1;
	cin>>n>>m>>x;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m-1;i++){
		if(a[i]>x){
			d=x;
			x=a[i];
			a[i]=d;
		}
	}
	for(int i=1;i<=n*m-1;i++){
		if(i<=n){
			c=1;
			r=i;
		}
		else{
			j++;
			if(j%2==0){
				c=i-n;
				r=j;
			} 
			else{
				c=i-n;
				r=j+1;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
