#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
struct node{
	int g;
	int id;
}a[150];
int H,L;
bool cmp(node c,node b){
	return c.g>b.g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].g;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			x=i;
			break;;
		}
	} 
	int tmp=x%(2*n);
	if(tmp<=n&&tmp!=0){
		H=tmp;
	}else if(tmp>n){
		H=2*n-tmp+1;
	}else{
		H=1;
	}
	int tmp1=x%n;
	if(tmp1){
		L=x/n+1;
	}else{
		L=x/n;
	}
	cout<<L<<' '<<H;
	return 0;
}
