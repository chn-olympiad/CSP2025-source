#include<bits/stdc++.h>
using namespace std;
int n,m,seat,p,l;
struct node{
	int mark;
	int id;	
}a[101];
bool cmp(node x,node y){
	return x.mark>y.mark;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].mark;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) seat=i;
	}
	p=(seat-1)/n+1;
	seat=(seat-1)%n+1;
	if(p%2) l=seat;
	else l=m-seat+1;
	cout<<p<<" "<<l;
	return 0;
}
