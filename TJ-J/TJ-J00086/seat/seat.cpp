#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPJ std
LANH AK CSPJ;
typedef long long ll;
int n,m;
int a[1000009];
bool cmp(int x,int y){
	return x>y;
}
int st;
int ji;
int ro,co;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	st=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		ji=i;
		if(a[i]==st)break;
	}
	co=int((ji-1)/n)+1;
	if(co%2){
		ro=(ji-1)%n+1;
	}
	else{
		ro=n-(ji-1)%n;
	}
	cout<<co<<' '<<ro;
	return 0;
}

