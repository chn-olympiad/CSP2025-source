#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000;
int n,m;
int a[N];
int now;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	now=a[1];
	sort(a+1,a+1+n*m);
	int tot=lower_bound(a+1,a+1+n*m,now)-a;
	tot=(n*m-tot+1);
	int c=(tot/n),r;
	tot=tot-c*n;
	if(tot==0){
		if(c%2==0) r=1;
		else r=n;
	}
	else{
		c++;
		if(c%2==1) r=tot;
		else r=n-tot+1;
	}
	cout<<c<<" "<<r; 
	return 0;
} 
