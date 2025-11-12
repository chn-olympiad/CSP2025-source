#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,o,f[15][15];
struct node{
	long long x;
	bool fl;
}a[105];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].x;
	a[1].fl=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(a[i].fl==1)
	o=i;
	for(int j=1;j<=m;j++){
		if(j&1){
		for(int i=1;i<=n;i++){
			f[i][j]=j*(j-1)+i;
		}
		}
		else{
		for(int i=n;i>=1;i--){
			f[i][j]=2*n+1-i;
		}	
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(f[i][j]==o){
			cout<<j<<" "<<i;
			return 0;
		}
	}
	return 0;
}
