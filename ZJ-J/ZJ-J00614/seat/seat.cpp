#include <bits/stdc++.h>
using namespace std;
int n,m,c,k,x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int mark;
		cin>>mark;
		if(i==1){
			c=1;k=mark;
		}
		else if(mark>k)c++;
	}
	if(c%n==0){
		x=c/n;
		y=n;
	}else{
		x=c/n+1;
		y=c%n;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
