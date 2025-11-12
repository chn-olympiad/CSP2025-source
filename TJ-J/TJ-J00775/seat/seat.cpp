#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,nownum;
struct node{
	long long n,num;//数值,下标 
};
node a[105];
bool cmp(node x,node y){
	return x.n>y.n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i].n;
		a[i].num=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i].num==1){
			nownum=i;
			break;
		}
	}
	if(nownum%n){
		c=nownum/n+1;
	}else{
		c=nownum/n;
	}
	if(c==1){
		r=nownum;
	}else if(c%2){
		if(nownum%n==0){
			r=n;
		}else{
			r=nownum%n;
		}
	}else{
		if(nownum%n==0){
			r=1;
		}else{
			r=n-(nownum%n)+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
