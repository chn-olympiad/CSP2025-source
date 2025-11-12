#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[9999999];

bool cmp(long long x,long long y){
	return x>y;
}

long long up_(long long x,long long y){
	if(x % y == 0){
		return x/y;
	}
	return x/y+1;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	if(n == 1 && m == 1){
		cout<<1<<' '<<1;
	}
	
	for(long long i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r = a[0];
	
	sort(a,a+n*m,cmp);
	
	for(int i = 0;i<n*m;i++){
		if(a[i] == r){
			long long x,y;
			x = up_(i+1,n);
			
			if(x%2 == 1){
				y = i%n+1;
			}
			else{
				y = n-(i%n);
			}
			cout<<x<<' '<<y<<endl;
			return 0;
		}
	}
	return 0; 
}
