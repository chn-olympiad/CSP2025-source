#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[210],z,x,y,w,ex,ey;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}z=a[1];
	sort(a+1,a+n*m+1);
	x=1;y=1;w=1;
	ex=1;ey=0;
	if(z==a[w]){
		cout<<x<<" "<<y;
		return 0;
	}
	while(w<=n*m){
		if(w%n==0){
			ex=0;ey=1;
		}if(w%(2*n)==n+1){
			ex=-1;
			ey=0;
		}if(w%(2*n)==1){
			ex=1;ey=0;
		}
		x+=ex;y+=ey;
		w++;
		if(z==a[n*m-w+1]){
			cout<<y<<" "<<x;
			return 0;
		}
	}
	return 0;
}
