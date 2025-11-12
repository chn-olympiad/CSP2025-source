#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N];
int ans[N][N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;

	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	long long t=a[1];	
	sort(a+1,a+n*m+1,cmp);
	long long x=1;
	for(long long i=1;i<=n*m;i++){
		if(a[i]==t){
			x=i;
			break;
		}
	}
	
	long long b=x%n;
	long long c=0;
	if(b==0){
		c=x/n;
	}else{
		c=x/n+1;
	}
	if(c%2==1){
		if(b==0){
			cout<<c<<" "<<n;
		}else{
			cout<<c<<" "<<b;
		}
		
	}else{
		if(b==0){
			cout<<c<<" "<<n;
		}else{
			cout<<c<<" "<<n-b+1;
		}
	
	}
	return 0;
} 
