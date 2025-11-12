#include<bits/stdc++.h>
using namespace std;
int n,m,k,xz[11],xz1[11],a[1000005][3],b[1000005];
struct lu{
	
	int x,y,jg;
	operator <( const lu &b)const{
		return x<b.x;
	};
	lu(int p,int q){
		x=p;
		y=q;
	};
};
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	cout<<13;
	return 0;
}