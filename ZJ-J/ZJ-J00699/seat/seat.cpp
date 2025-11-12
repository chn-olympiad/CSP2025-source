#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t1,t2,xx,yy;
bool cmp(int x,int y){
	return x>y;
}
void find(){
	int l=1,r=n*m,mid=(l+r)/2;
	while(l<=r){
		if(t1==a[mid]){
			t2=mid;
			break;
		}
		if(t1<a[mid])
			l=mid+1;
		if(t1>a[mid])
			r=mid;
		mid=(l+r)/2;
	}
}
int main(){
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t1=a[1];
	sort(a+1,a+1+n*m,cmp);
	find();
	//cout<<t2<<'\n';
	xx=ceil(t2*1.0/n);
	if(xx%2){
		yy=t2%n;
		if(yy==0)
			yy=m;
	}
	else yy=m-(t2-1)%n;
	cout<<xx<<' '<<yy;
	return 0;
}
