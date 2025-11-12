#include<bits/stdc++.h>
using namespace std;
const int N=10+5;
int n,m,a,ot,ans,sum=1,l,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	l=n*m;
	l--;
	while(l--){
		cin>>ot;
		if(ot>a)sum++;
	}b=(sum+n-1)/n;
	sum=sum-(b-1)*n;
	if(b%2==0){
		sum=n-sum+1;
	}cout<<b<<' '<<sum;
	return 0; 
} 
