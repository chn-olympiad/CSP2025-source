#include<bits/stdc++.h>
using namespace std;
int n,m,a1,mc=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>a1)mc++;
	}
	cout<<(mc+n-1)/n<<' ';
	if((mc+n-1)/n%2==1){
		cout<<(mc-1)%n+1;
	}
	else{
		cout<<n-(mc-1)%n;
	}
	return 0;
}
