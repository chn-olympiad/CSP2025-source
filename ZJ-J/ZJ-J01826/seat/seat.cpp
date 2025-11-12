#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,r;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	c=(k+n-1)/n;
	if(c%2==1){
		r=k-(c-1)*n;
	}
	else{
		r=n-k+(c-1)*n+1;
	}
	cout<<c<<' '<<r;
	return 0;
} 
