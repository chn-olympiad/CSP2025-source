#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],b=1,c=1,d;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	d=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			if(a[j]==d){
				b=j+1;
			}
		}
	}
	if(b%n==0){
		cout<<b/n<<" "<<n;
	}
	else{
		cout<<b/n+1<<" "<<b%n;
	}
	return 0;
} 
