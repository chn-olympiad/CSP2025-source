#include<bits/stdc++.h>
using namespace std;
int n,m,R,xr,c,r,cnt;
int a[110];
bool c1(int x){
	if(x%n==0) return true;
	else return false;
}
bool c2(int x){
	if(x%2==1) return true;
	else return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) R=a[i];
	}
	sort(a+1,a+n*m+1);
	cnt=1;
	for(int i=n*m;i>=1;i--,cnt++){
		if(a[i]==R){
			xr=cnt;
			break;
		}
	}
	if(c1(xr)) c=xr/n;
	if(!c1(xr)) c=(xr/n)+1;
	if(c2(c)){
		for(int i=1;i<=n;i++)
			if(n*(c-1)+i==xr) r=i;
	}
	if(!c2(c)){
		for(int i=n,cnt=1;i>=1;i--,cnt++)
			if(n*(c-1)+i==xr) r=cnt;
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
