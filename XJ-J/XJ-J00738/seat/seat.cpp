#include<bits/stdc++.h>
using namespace std;
int n,m,a,me,tot=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>me;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>me) tot++;
	}
	x=tot%n;
	y=tot/n;
	if(tot%n!=0){
		y+=1;
		if(y%2==0) x=n-x+1;
	}
	else{
		if(y%2==0) x+=1;
		else x=n;
	}
	cout<<y<<' '<<x;
	return 0;
} 
