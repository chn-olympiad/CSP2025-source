#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn],n,m,R,pos,r,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==R)pos=i;
	if(pos%n==0)c=pos/n;
	else c=pos/n+1;
	if(c%2==0){
		if(pos%n==0)r=1;
		else r=n-pos%n+1;
	}else{
		if(pos%n==0)r=n;
		else r=pos%n;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
