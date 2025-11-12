#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[105],a1,x,y,x1,y1;
	int b[15][15];
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	a1=a[1];
	for(int i=1;i<=n*m;i++)
		for(int j=1;j<=i;j++)
			if(a[i]>a[j]) swap(a[i],a[j]);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			a1=i;
			break;
		}
	}
	if(n==1){
		cout<<a1<<1;
		return 0;
	}
	if(m==1){
		cout<<1<<a1;
		return 0;
	}
	x=a1%n;
	y=a1%m;
	if(x==0) x1=a1/n;
	else x1=a1/n+1;
	if(x1%2==0){
		if(y==0) y1=1;
		else if(n%2==0) y1=n-y+1;
		else if(n%2!=0) y1=n-y;
	}else{
		if(y==0) y1=n;
		else y1=y ;
		}
		cout<<x1<<" "<<y1;
	return 0;	
}
