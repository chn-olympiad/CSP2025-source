#include <bits/stdc++.h>
using namespace std;
int A[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,r1,x=1,y=0;cin>>n>>m;
	cin>>r;
	A[0]=r;
	for(int i=1;i<n*m;i++){
		cin>>A[i];
	}
	sort(A,A+n*m-1);
	for(int i=n*m-1;i>=0;i--){
		if(A[i]==r){
			r1=i;
			break;
		} 
	}
	r1=n*m-r1-1;
	int c=r1%(2*n),d=r1/(2*n);
	x+=2*d;
	if(c==0){
		x++;
		y=1;
	}
	else if(c<=n){
		y=c;
	}
	else if(c>n){
		x++;
		y=2*n-c+1;
	}
	cout<<x<<' '<<y;
	return 0;
}

