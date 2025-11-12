#include <bits/stdc++.h>
using namespace std;
bool o(int x,int y){
	return x<=y;
}
int z[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a=0,b=0;
	cin>>n;
	if(n=3){
		for(int i=0;i<n;i++){
			cin>>z[i];
		}
		sort(z,z+3,o);
		if(z[0]+z[1]<=z[2]){
			cout<<'0';
		}
		else{
			cout<<1;
		}
	}
	if(n=4){
		for(int i=0;i<n;i++){
			cin>>z[i];
			b=b+z[i];
		}
		sort(z,z+3,o);
		if(z[0]+z[1]<=z[2]){
			cout<<'0';
			a++;
		}
		if(z[0]+z[1]<=z[3]){
			cout<<'0';
			a++;
		}
		if(z[0]+z[2]<=z[3]){
			cout<<'0';
			a++;
		}
		if(z[1]+z[2]<=z[3]){
			cout<<'0';
			a++;
		}
		if(b>z[3]*2){
			a++;
		}
	}
	cout<<a;
	return 0;
}
