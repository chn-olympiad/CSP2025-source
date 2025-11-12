#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm;
	cin>>n>>m;
	nm=n*m;
	int k,o,p=0;
	cin>>k;
	for(int i=2;i<=nm;i++){
		scanf("%d",&o);
		if(o>k) p++;
	}
	int x=p/(2*n),y=p%(2*n);
	if(y<n){
		cout<<2*x+1<<" "<<y+1;
	}else{
		cout<<2*x+2<<" "<<2*n-y;
	}
	return 0;
}
