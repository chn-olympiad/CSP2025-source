#include<bits/stdc++.h>
using namespace std;
int n,m;
int g,p;
int x,y;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	g=a[0];
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++){
//		cout<<a[i];
		if(a[i]==g){
			p=i;
			break;
		}
	}
	//cout<<p<<endl;
	x=p/n+1;
	if(x%2==1){
		y=p%n+1;
	}
	else{
		y=n-p%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
/*
2 2
99 100 97 98
*/
