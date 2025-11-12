#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	for(int i=0;i<n*m;i++){
		if(a[i]<a[i+1]){
			x=a[i];
			a[i]=a[i+1];
			a[i+1]=x;
		}
	}
	for(int i=0;i<n*m;i++){
		if(r==a[i]){
			r=a[i];
		}
	}
	cout<<r/n<<" "<<r/m;
	return 0;
}
