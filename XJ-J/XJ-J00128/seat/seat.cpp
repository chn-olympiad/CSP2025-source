#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
long long a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c=0,r=0;
	cin>>n>>m;
	
	long long p=m*n;
	long long p1=p;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	long long R=a[1];
	while(p--){
		for(int i=1;i<=p1;i++){
			long long step=0;
			if(a[i]<a[i+1]){
				step=a[i];
				a[i]=a[i+1];
				a[i+1]=step;
			}
		}
	}
	for(int i=1;i<=p1;i++){
		if(a[i]==R){
			if(i%n==0){
				c=i/n;
				cout<<c<<" "<<n;
			} else{
				c=i/n;
				c=c+1;
				if(c%2==0) r=n-i%n+1;
				if(c%2!=0) r=i%n;
				cout<<c<<" "<<r;
			}
		}
	}
	return 0;
}
