#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,c=1,r=1,cj;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj;
		if(a1=cj){
			r+=i;
		}
		if(r>m){
			c+=1;
			r=1;
		}
		if(c>n){
			r+=1;
			c=1;
		}
	} 
	cout<<c<<" "<<r;
	return 0;
}
