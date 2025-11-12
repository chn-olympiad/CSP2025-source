#include<bits/stdc++.h>
using namespace std;
int n,m,k,x=1,y=1,cnt=0,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>k)
		    cnt++;
	}
	for(int i=0;i<cnt;i++){
		if(y%2==0){
			x--;
		    }
		else if(y%2==1)
		    x++;
		if(x>n||x<1){
			y++;
			if(y%2==0){
			x--;
		    }
		    else if(y%2==1)
		        x++;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
