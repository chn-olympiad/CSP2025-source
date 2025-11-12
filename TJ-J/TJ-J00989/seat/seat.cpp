#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int mk;
	int id;
}a[105];
bool cmp(node a,node b){
	return a.mk>b.mk;
}
int wz;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].mk;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			wz=i;
			break;
		}
	}
	if(wz%n==0){
		x=wz/n;
	}else{
		x=wz/n+1;
	}
	int y=wz%n;
	if(y==0){
		y=n;
	}
	if(x%2==0){
		y=n+1-y;
	}
	cout<<x<<' '<<y;
	return 0;
}
