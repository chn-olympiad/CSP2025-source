#include<bits/stdc++.h>
using namespace std;
int n,m,x,nm,nw=1,nx=1,ny=1,sum;
int b[105],a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	sum=1;
	for(int i=1;i<=nm;i++){
		cin>>b[i];
		if(i==1)
			x=b[i];
	}
	sort(b+1,b+nm+1);
	for(int i=nm;i>=1;i--){
		a[sum]=b[i];
		sum++;
	}
	while(a[nw]!=x){
		if(ny%2==1&&nx==n)
			ny++;
		else if(ny%2==0&&nx==1)
			ny++;
		else if(ny%2==1)
			nx++;
		else if(ny%2==0)
			nx--;
		nw++;
	}
	cout<<ny<<' '<<nx;
	return 0;
}
