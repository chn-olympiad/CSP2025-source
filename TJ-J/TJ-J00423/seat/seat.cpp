#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[101];
long long r;
long long l;
long long x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==r){
			l=n*m-i;
		}
	}
	x=l/(n*2);
	y=l%(n*2);
	if(y<=n){
		cout<<x*2+1<<" "<<y;
	}
	else{
		cout<<x*2+2<<" "<<2*n-y+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

