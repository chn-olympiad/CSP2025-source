#include<bits/stdc++.h>

using namespace std;

int a[101],n,m,r;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m);
	int x=1,y=0; 
	for(int i=n*m;i>=1;i--){
		if(x%2!=0){
			y++;
		}else{
			y--;
		}

		if(y>n){
			x++;
			y--;
		}else if(y<1){
			y++;
			x++;
		}
		if(a[i]==r){
			cout<<x<<' '<<y;
			return 0;
		}
	}
	return 0;
	
 } 
