#include<bits/stdc++.h>
using namespace std;
long n,m,a[120],s,sum,x,y;
bool q(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,q);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			sum=i;
			break;
		}
	}
	if(sum%n==0){
		x=sum/n;
		if(x%2==0){
			y=n-(sum/n)+1;
		}else{
			y=sum%(2*n);
		}
	}else if(sum%n!=0){
		x=sum/n+1;
		if(x%2==0){
			y=n-(sum/n)+1;
		}else{
			y=sum%(2*n);
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
