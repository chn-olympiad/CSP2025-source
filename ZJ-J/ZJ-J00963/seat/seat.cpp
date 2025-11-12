#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[1000005],sc,w,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc){
			w=i;
			break;
		}
	}
	if(w%n==0) l=w/n;
	else l=w/n+1;
	if(w%n==0){
		if(l%2) h=n;
		else h=1;
	}
	else{
		if(l%2) h=w%n;
		else h=n-w%n+1;
	}
	cout<<l<<' '<<h;
	return 0;
}
