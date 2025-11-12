#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,s,e;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	e=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				s=a[j];
				a[j]=a[j+1];
				a[j+1]=s;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(e==a[i]){
			e=i;
			break;
		}
	}
	c=e/m+1;
	if(e%m!=0){
		if(c%2==1){
		r=e%m;
		}else{
		r=m-(e%m)+1;
		}
	}else{
		c=e/m;
		r=m;
	}
	cout<<c<<" "<<r;
	return 0;
}
