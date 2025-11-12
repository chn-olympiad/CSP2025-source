#include<bits/stdc++.h>
using namespace std;
int x,y,z,n,m,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++){
		cin>>y;
		if(y>x) z++;
	}
	z++;
	for(int i=1;i<=m;i++){
		if(!z) break;
		l=i;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(z) z--;
				else break;
				r=j;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(z) z--;
				else break;
				r=j;
			}
		}
	}
	cout<<l<<" "<<r;
	return 0;
}