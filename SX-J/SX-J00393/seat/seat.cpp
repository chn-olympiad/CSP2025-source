#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5],x;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	int y=1;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x)break;
		y++;
	}
	int c=y/n+1,r=y%n;
	if(c%2==0&&r==0){
		r=n;
		c-=1;
	}else if(c%2==0&&r!=0){
		r=n+1-r;
	}else if(r==0){
		r=1;
		c-=1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}