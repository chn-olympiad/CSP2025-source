#include<bits/stdc++.h>
using namespace std;
int n,m,k,f,l,cnt=1,x,y; 
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	k=n*m;
	cin>>f;
	for(int i=1;i<k;i++){
		cin>>l;
		if(l>f){
			cnt++;
		}
	}
	x=cnt/n+1;
	y=cnt%n;
	if(x%2==1){
		if(y==0){
			cout<<x-1<<" "<<n;
		}else{
			cout<<x<<" "<<"1";
		}
	}
	if(x%2==0){
		if(y==0){
			cout<<x-1<<" "<<n;
		}
		else{
			cout<<x<<" "<<n-y+1;
		}
	}
	return 0; 
}
