#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	int y=n*m;
	sort(a+1,a+y+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			break;
		}
	}
	int c,r;
	if(x%m==0){
		c=x/m;
	}
	else c=x/m+1;
	if(c%2==1){
		if(x%m==0)r=m;
		else r=x%m;
	}
	else r=m-(x%m)+1;
	cout<<c<<" "<<r;
	return 0;
}
