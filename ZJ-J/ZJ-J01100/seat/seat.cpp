#include<bits/stdc++.h>
using namespace std;
struct node{
	int test,id;
}a[1010];
bool cmp(node x,node y){
	return x.test>y.test;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].test;
		a[i].id=i;
	}
	int f=a[1].test ,k=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) 
		if(a[i].test ==f) k=i;
	if(n==1||m==1){
		if(n==1&&m==1) cout<<1<<" "<<1;
		else if(n==1) cout<<1<<" "<<k;
		else cout<<k<<" "<<1;
		return 0;
	}
	int b,c;
	b=k/n;
	c=k%n;
	if((b+1)%2==0) cout<<b+1<<" "<<n-c+1;
	else cout<<b+1<<" "<<c;
	return 0;
}
