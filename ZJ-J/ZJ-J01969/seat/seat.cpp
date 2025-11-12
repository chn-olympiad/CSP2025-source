#include<bits/stdc++.h>
using namespace std;
struct node{
	int no;
	int v;
};
int n,m,ay;
node a[110000];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].no=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int wz=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].no==1){
			wz=i;
			break;
		}
	}
	int x,y;
//	cout<<wz<<"\n";
	if(wz%n==0){
		x=wz/n;
	}else{
		x=wz/n+1;
	}
	y=(wz-1)%n+1;
	if(x%2==1){
		ay=y;
	}else{
		ay=n-y+1;
	}
	cout<<x<<" "<<ay;
	return 0;
}
