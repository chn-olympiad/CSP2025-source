#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int c;
	int p;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	//for(int i=1;i<=n*m;i++){
	//	cout<<a[i];
	//}
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	//for(int i=1;i<=n*m;i++){
	//	cout<<a[i];
	//}
	for(int i=1;i<=m*n;i++){
		if(c==a[i]){
			p=i;
			break;
		}
	}
	//cout<<p<<" ";
	int l;
	int y;
	if(p%n!=0){
		l=p/n+1;
		y=p%n;
		if(l%2==0){
			cout<<l<<" "<<n-y+1;
			return 0;
		}
		else{
			cout<<l<<" "<<y;
			return 0;
		}
	}
	else{
		l=p/n;
		if(l%2==0){
			cout<<l<<" "<<"1";
			return 0;
		}
		else{
			cout<<l<<" "<<n;
			return 0;
		}
		return 0;
	}
	return 0;
}
