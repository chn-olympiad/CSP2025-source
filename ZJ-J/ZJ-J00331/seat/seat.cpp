#include<bits/stdc++.h>
using namespace std;

const int maxx=105;
int n,m,a[maxx],num,c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		if (i==1) num=a[1];	
	}
	sort(a+1,a+n*m+1);
	int j=lower_bound(a+1,a+n*m+1,num)-a;
	j=n*m-j+1;
	if (j%n!=0){
		c=j/n+1;
		if (c%2==1) r=j%n;
		else r=n-j%n+1;
	}
	else{
		c=j/n;
		if (c%2==1) r=n;
		else r=1;
	}
	cout<<c<<" "<<r;
	return 0;
}
