#include<bits/stdc++.h>
using namespace std;
int n,m,a1,x,num=1,k,j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>a1) num++;
	}
	k=num/n;
	j=num%n;
	if(j==0){
		k--;
		j=n;
	} 
	k++;
	if(k%2==0) j=n+1-j;
	cout<<k<<" "<<j;
	return 0;
}
