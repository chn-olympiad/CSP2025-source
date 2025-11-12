#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,f,X,Y;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			f=i;
			break;
		}
	}
	X=(f+n-1)/n;
	Y=(f-1)%n+1;
	if(X%2==0)Y=n-Y+1;
	cout<<X<<" "<<Y;
	return 0;
}
