#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			s=i;
			break;
		}
	}
	int c=(s+n-1)/n,t=s%(2*n),r;
	if(t>n){
		t-=n;
		r=n+1-t;
	}
	else{
		r=t;
	}
	cout<<c<<" "<<r;
	return 0;
}
