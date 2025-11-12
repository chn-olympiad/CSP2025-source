#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],b,c,d,x,f;
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	b=a[0];
	sort(a,a+n*m);
	reverse(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==b) c=i+1;
	}
	d=c;
	if(c%n==0) c/=n;
	else c=c/n+1;
	if(c%2==1){
		if(d%n!=0){
			d=d%n;	
		}
		else{
			d=n;
		}
	}
	else{
		if(d%n!=0){
			d=n-d%n+1;
		}
		else{
			d=1;
		}
	}
	cout<<c<<' '<<d;
	return 0;
} 
