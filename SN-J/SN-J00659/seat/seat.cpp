#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c,r;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int s=a[0];
	while(1){
		int k=1;
		for(int i=0;i<n*m-1;i++){
			if(a[i]<a[i+1]){
				int d=a[i];
				a[i]=a[i+1];
				a[i+1]=d;
				k=0;
			}
		}
		if(k==1){
			break;
		}
		
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==s){
			b=i;
		}
	}
	c=b/n+1;
	if(m%2==1){
		r=b%n;
	}
	else if(n%2==0){
		r=(n+1)-(b%n);
	}
	cout<<c<<' '<<r;
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
