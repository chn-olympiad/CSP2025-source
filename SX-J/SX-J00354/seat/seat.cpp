#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,b=0,cnt=0,c=0,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];

	for(int j=1;j<=n*m-1;j++){
		for(int i=1;i<=n*m;i++){
			if(a[i]<a[i+1]){
				int a1=a[i];
				a[i]=a[i+1];
				a[i+1]=a1;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cnt=i;
			break;
		}
	}

	if(cnt%n==0){
		c=cnt/n;
	}
	else {
		c=cnt/n;
		c=c+1;
	}
	if(c%2==1){
		r=cnt-(c-1)*n;
	}
	else{
		r=m+1-cnt+(c-1)*n;
	}
	cout<<c<<" "<<r;
	return 0;
}