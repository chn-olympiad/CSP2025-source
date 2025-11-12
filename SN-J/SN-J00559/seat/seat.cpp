#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int a,s;
}a[101];
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1].s;
	a[1].a=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].s;
		a[i].a=i;
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].a==1){
			int c=(i-1)/n+1,r;
			if(c%2==1) r=i-n*(c-1);
			else r=n*c-i+1;
			cout<<c<<" "<<r;
			return 0;
		}
	}
}
