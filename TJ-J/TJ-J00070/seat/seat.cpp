#include<bits/stdc++.h>
using namespace std;
int main(){
	//b=小R 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,p=0,r=0,c=0;
	cin>>n>>m;
	int a[n*m]={0},b;//一定要过！！！！！ 
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		b=a[0];
	}
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==b){
			p=abs(i-n*m);
			break;
		}
	}
	c=p/n;
	if(c%n!=0) c++;
	if(c%2==1) r=p%n;
	else r=n-p%n+1;
	if(r==0) r=n;
	cout<<c<<' '<<r<<'\n';
	return 0;
}
//好运来，祝我好运来 ！！！！ 
