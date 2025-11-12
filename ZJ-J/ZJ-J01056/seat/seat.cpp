#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,ip,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			ip=i;
			break;
		} 
	}
	x=ceil(1.0*ip/n);
	if(x%2==0){
		y=n-(ip%n)+1;
	}
	else{
		y=ip%n;
		if(y==0) y=n;
	}
	cout<<x<<" "<<y;
	return 0;
}

