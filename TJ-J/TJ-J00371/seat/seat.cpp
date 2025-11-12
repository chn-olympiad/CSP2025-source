#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[150]={0};
	for(int i=0;i<n*m;++i){
		cin>>a[i];
	}
	int sum,ans=1;
	for(int i=1;i<=n*m;++i){
		if(a[i]>a[0]) ans++;
	}
	int x,y;
	y=(ans-1)/n+1;
	if(y%2==1){
		x=ans-n*(y-1);
	}
	else{
		x=n-(ans-n*(y-1))+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
