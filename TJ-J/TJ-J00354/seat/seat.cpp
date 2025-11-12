#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long u=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	u=a[1];
	long long R=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==u){
			R=i;
			break;
		}
	}
	long long l=0,h=0;
	if(R%n==0){
		l=R/n;
	}else{
		l=R/n+1;
	}
	if(l%2==0){
		if(R%n==0){
			h=1;
		}else{
			h=n-(R%n)+1;
		}
		
	}else{
		if(R%n==0){
			h=n;
		}else{
			h=R%n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
} 
