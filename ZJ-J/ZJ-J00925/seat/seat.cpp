#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int n,m,r,j,a1,b1;
int a[105];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+c+1,cmp);
	for(int i=1;i<=c;i++){
		if(b[i]==r){
			j=i;
			break;
		}
	}
	if(j<=n) {
		a1=1;
		b1=j;
	}
	else{
		a1=j/n+1;
		if(a1%2==0){
			b1=n-j%n+1;
		}
		else b1=1+j%n-1;
	} 
	cout<<a1<<" "<<b1;
	return 0;
}
