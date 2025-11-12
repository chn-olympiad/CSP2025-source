#include<bits/stdc++.h>
using namespace std;
int n,m,l=1;
struct node{
	bool id;
	int v;
}a[1009];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1) a[i].id=1;
		else a[i].id=0;
		cin>>a[i].v;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[(i-1)*n+j].id==1){
					cout<<i<<" "<<(n-j+1);
					return 0;
				}
			}
		}
	}
	return 0;
}
