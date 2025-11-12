#include <bits/stdc++.h>
using namespace std;
int n,m,ach[110],ai[110],c=0,r=0;
int main(){
	cin>>n>>m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=0;i<n*m;i++){
		cin>>ach[i];
		a1=ach[0];
	}
	for(int i=0;i<n*m;i++){
		if(i%2==1){
			sort(ach,ach+n*m);
			cin>>ai[i];
			ach[i]-=n;
			r++;
		}
		if(i%2==0){
			sort(ach+n*m,ach);
			cin>>ai[i];
			ach[i]-=n;
			r++;
		}
		c++;
	}
	cout<<c<<" "<<r;
	return 0;
}