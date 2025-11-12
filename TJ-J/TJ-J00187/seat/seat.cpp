#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n=0,m=0,r,r1,s=1;
	cin>>n>>m>>r;
	for(int i=2;i<=n*m;i++){
		cin>>r1;
		if(r1>r){
			s++;
		}
	}
	cout<<(s+n-1)/n<<" ";
	if(((s+n-1)/n)%2==1){
		if(s%n==0){
			cout<<n;
		}else{
			cout<<s%n;
		}
	}else{
		if(s%n==0){
			cout<<1;
		}else{
			cout<<n+1-s%n;
		}
	}
	return 0;
}
