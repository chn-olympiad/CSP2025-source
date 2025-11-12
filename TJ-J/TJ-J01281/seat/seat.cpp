#include<bits/stdc++.h>
using namespace std;
long long n,m,R,x=0,y=0,z=0,Max=0,a[101];
int main(){
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	cin>>n>>m;x=n;y=m;
	if(n==1 && m==1){
		cout<<n<<' '<<m;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			Max=a[i];
			R=1;
		}else if(a[i]>Max){
			Max=a[i];
			R+=1;
		}
	}
	x=R/n;y=R%n;z=x%2;
	if(z==1){
		z=z-y+1;
		cout<<x<<' '<<z;
	}else{
		x+=2;z+1;
		cout<<x<<' '<<z;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
