#include<bits/stdc++.h>
using namespace std;
int n,m,u=0,k[105],x,y;


int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>k[i];
	}
	sort(k+1,k+n*m);
	for(int i=1;i<n*m;i++){
		if(k[0]>k[i]){
			u=i;
		}else{
			break;
		}
	}
	u++;
	if(u%n==0){
		y=u/n;
	}else{
		y=u/n+1;
	}
	if(y%2==1){
		x=n-(u%n);	
	}else if(y%2==0){
		x=n-(u%n-1);
	}
	cout<<x<<' '<<y;
	return 0;
}
