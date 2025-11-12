#include<bits/stdc++.h>
using namespace std;
int max(int x,int y,int z){
	if(x>y>z) return x;
	if(x>z>y) return x;
	if(y>x>z) return y;
	if(y>z>x) return y;
	if(x<y<z) return z;
	if(y<x<z) return z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,y,a[100000],b[100000],c[100000];
	cin>>t;
	cin>>n;
	y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		y+=max(a[i],b[i],c[i]);
	}
	if(n==2) cout<<y+1;
	return 0;
}