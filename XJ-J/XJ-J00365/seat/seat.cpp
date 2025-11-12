#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int m=x*y;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int b[105];
	for(int i=1;i<=100;i++){
		b[i]=0;
	}
	for(int i=1;i<=m;i++){
		b[a[i]]=1;
	}
	int c[105];
	int ans=1;
	for(int i=0;i<=100;i++){
		if(b[i]==1){
			c[ans]=i;
			ans++;
		}
	}
	int n;
	for(int i=1;i<=m;i++){
		if(c[i]==a[1]){
			n=i;
		}
	}
	n=m+1-n;
	int dx,dy=(n-1)/x+1;
	if(dy%2==1){
		dx=n%x;
		if(dx==0){
			dx=x;
		}
	}else{
		dx=n%x;
		if(dx==0){
			dx=x;
		}
		dx=x+1-dx;
	}
	cout<<dy<<" "<<dx;
	cout<<endl;
	return 0;
}
