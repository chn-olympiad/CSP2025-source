#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
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
	int sb=a[1];
	int bj=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sb){
			bj=i;
		}
	}
	int x=0,y=0;
	if((bj/n+1)%2==0&&bj%n!=0){
		y=bj/n+1;
		x=n-bj%n+1;
	}
	else if((bj/n+1)%2==1&&bj%n!=0){
		y=bj/n+1;
		x=bj%n;
	}
	else if((bj/n)%2==1&&bj%n==0){
		y=bj/n;
		x=n;
	}
	else if((bj/n)%2==1&&bj%n==0){
		y=bj/n;
		x=1;
	}
	cout<<y<<' '<<x;
	return 0;
}
