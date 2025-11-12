#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	num=1;
	for(int i=2;i<=n*m;i++){
		int t;
		cin>>t;
		if(t>k){
			num++;
		}
	}
	if((num/n)%2==0){
		if(num%n==0){
			x=num/n;
			y=1;
		}
		else{
			x=num/n+1;
			y=num%n;
		}
	}
	else{
		if(num%n==0){
			x=num/n;
			y=n;
		}
		else{
			x=num/n+1;
			y=n-num%n+1;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
