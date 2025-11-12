#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[105][105];
int a[105],mx,l;
int main(){
	cin>>n>>m;
	int d=n*m;
	for(int i=0;i<d;i++){
		cin>>a[i];
		if(a[i]>mx)mx=a[i];
		a[l]=mx;
		l++;
	}
	for(int i=0;i<d;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
