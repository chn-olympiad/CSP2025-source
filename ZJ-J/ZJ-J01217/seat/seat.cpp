#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c=1,r,l;
bool f;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+1+n*m,cmp);
	do{
		l++;
		if(f==0){
			if(r<n)r++;
			else f=1,c++;
		}
		else{
			if(r>1)r--;
			else f=0,c++;
		}
	}while(a[0]!=a[l]);
	cout<<c<<' '<<r;
	return 0;
}
