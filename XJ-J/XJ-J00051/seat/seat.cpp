#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[11000];
	int c,r;
	freopen("seat.in","r",stdin);
	freopen("seat.out","d",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++) {
		for(int j=1;j<=m;j++){
			if(a[i]<a[i+1]){
				int v=a[i+1];
				a[i+1]=a[i];
				a[i]=v;
			}
		}
	}
	cout<<c<<r;
	return 0;
}
