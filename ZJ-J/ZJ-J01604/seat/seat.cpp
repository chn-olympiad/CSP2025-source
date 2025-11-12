#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,a[10005],t,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			t=n*m+1-i;
			break;
		}
	}
	if(t%n==0){
		r=t/n;
		if(r%2){
			c=n;
		}else{
			c=1;
		}
	}else{
		r=t/n+1;
		if(r%2){
			c=t%n;
		}else{
			c=n-(t%n)+1;
		}
	}
	cout<<r<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}