#include<bits/stdc++.h>
using namespace std;
int i,n,m,a[101],x=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0]=1;
	for(i=2;i<=n*m;i++){
		if(x%2==0){
			if(a[i]>a[1])
				a[0]--;
			if(a[0]<1){
				x++;
				a[0]=1;
			}
		}
		else{
			if(a[i]>a[1])
				a[0]++;
			if(a[0]>n){
				x++;
				a[0]=n;
			}
		}
	}
	cout<<x<<" "<<a[0];
	return 0;
}