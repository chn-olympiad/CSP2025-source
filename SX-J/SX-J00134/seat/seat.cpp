#include<bits/stdc++.h>
using namespace std;
int n,m,a[210],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		b=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=0;i<n*m;i++){
		if(m-1%m==m&&i/m+2<=m){
			x=i/m+2;
			y=m-i%m;
			//cout<<i/m+2<<" "<<1;
		}
		else
			x=i/m+1;
			y=m-i%m;
			//cout<<i/m+1<<" "<<m-i%m;
	}
	cout<<x<<" "<<y;
	return 0;
}