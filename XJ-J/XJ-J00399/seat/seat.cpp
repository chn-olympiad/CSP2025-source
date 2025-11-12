#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	long long k=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	if(k%n==0){
		cout<<k/n<<' ';
	}
	else if(k%n!=0){
		cout<<k/n+1<<' ';
	}
	x=k%(2*n);
	if(x==0){
		cout<<1;
	}
	else if(x<=n){
		cout<<x;
	}
	else if(x>n){
		cout<<2*n-k+1;
	}
	return 0;
} 
