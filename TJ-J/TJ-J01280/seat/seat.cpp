#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,x,y=0,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>z;
			if(i*j==1) x=z;
			a[z]++;
			
		}
	}
	for(int i=100;i>=x;i--){
		if(a[i]) y++;
	}
	//cout<<a[1]<<endl;
	for(int i=1;i<=n*m;i++){
		//cout<<a[i];
		if(a[i]==x){
			y=i;
		}
	}
	
	int c=(y-1)/n+1;
	int r=(y-1)%n+1;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;

	
}

