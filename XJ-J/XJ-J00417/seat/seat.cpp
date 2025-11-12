#include <bits/stdc++.h>
using namespace std;
int a[11001];

int main(){
	int n,m,x,r,b=1,c=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i];
		}
	}
	r=a[1];
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m;i++){
			if(a[i]>a[i-1]){
				x=a[i-1];
				a[i-1]=a[i];
				a[i]=x;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		//cout<<a[i];
		if(r==a[i]){
			r=i;
		}
	}
	int i=1,j=1;
	while(1){
		if(j%2==0){
			i--;
			c++;
			if(i==0){
				j++;
				i++;
		}
		}else{
			i++;
			c++;
			if(i==n+1){
				j++;
				i--;
		}
		}
		
		if(c==r){
			cout<<i<<" "<<j;
			return 0;
		}
	}
	
	return 0;
}
