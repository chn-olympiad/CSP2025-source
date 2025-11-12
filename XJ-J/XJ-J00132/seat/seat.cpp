#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int w=a[0];
	int xb=0;
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==w){
			xb=i+1;
		}
	}
	if(xb%m==0){
		cout<<m<<' ';
	}else{
		cout<<xb%m<<' ';
	}
	cout<<ceil(xb/n)+1<<' ';
	return 0;
}
