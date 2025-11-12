#include<bits/stdc++.h>
using namespace std;
int n,m,d,b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	for(int i=2;i<m;i++){
		for(int j=0;j<m-i;j++){
			if(a[i-1]<a[i+j]){
				d=a[i-1];
				a[i-1]=a[i+j];
				a[i+j]=d;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
		}
	}
	cout<<c/n+1<<" ";
	if((c/n+1)%2==0){
		cout<<n-c%n+1;
	}
	else if(c%n==0) cout<<n;
	else cout<<c%n;
	return 0;
}
