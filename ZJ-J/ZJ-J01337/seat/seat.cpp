#include<bits/stdc++.h>
using namespace std;
int a,m,n,amine,i,higher,myx,myy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>m>>n>>amine;
	
	for(i=1;i<m*n;i++){
		cin>>a;
		if(a>amine)higher++;
	}
	
	myx=higher/n+1;
	if(myx%2){
		myy=higher-n*myx+n+1;
	}
	else{
		myy=n*myx-higher;
	}
	
	cout<<myx<<' '<<myy;
	
	return 0;
}
