#include<bits/stdc++.h>
using namespace std;
int n,m;
int col,row;
int a,b,t=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a) t++;
	}
	col=floor(t/n);
	if(col%2==0){
		row=t%n+1;
	}
	else{
		row=n-t%n;
	}
	cout<<col+1<<" "<<row;
	return 0;
}
