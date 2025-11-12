#include <bits/stdc++.h>
using namespace std;
int a[110];
int n,m,z[15][15],f;
bool cmp(int x,int y){
	if(x!=y)
		return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++){
		cin>>a[i];
		if(i==1)	f=a[i];
	}
	sort(a+1,a+h+1,cmp);
	int t=0;
	for(int i=1;i<=h;i++)	if(a[i]==f)	t=i;
	int c,x;
	if((t%n)!=0)	c=floor(t/n)+1;
	else	c=t/n;
	if(c%2==1){
		if(t%n==0)
			x=n;
		else
			x=t%n;
	}
	else{
		if(t%n==0)
			x=1;
		else
			x=n-(t%n-1);
	}
	cout<<c<<" "<<x;
	return 0;
}
