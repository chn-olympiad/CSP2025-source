#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[1000],a1,x=1,y=1;
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<m*n;i++){
		cin>>a[i];
		if(y>n){
			y=0;
			x++;
			
	}
	if(a1<a[i]){
		y++;
			}
	}
	cout<<x<<" "<<y;
	return 0;
}
