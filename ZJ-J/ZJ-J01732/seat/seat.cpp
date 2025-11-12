#include<bits/stdc++.h>

using namespace std;
int n,m,a[110],R_Number,Where_R,R_x=1,R_y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R_Number=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==R_Number){
			Where_R=n*m-i+1;
		}
	}
	R_x=R_x+Where_R/n;
	if(Where_R%n==0)R_x--;
	R_y=Where_R%n;
	if(R_y==0)R_y=m;
	if(R_x%2==0){
		R_y=m-R_y+1;
	}
	cout<<R_x<<" "<<R_y;
	return 0;
}

