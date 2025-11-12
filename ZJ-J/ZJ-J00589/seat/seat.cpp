#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	int c=(int)ceil(p*1.0/n),r;
	if(c%2==1){
		r=p%n;
	}else{
		r=n-p%n+1;
	}
	if(r==0) r=n;
	cout<<c<<" "<<r<<endl;
	return 0;
}