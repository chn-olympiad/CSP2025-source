//yxt
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	int s[t];
	for(int i=1;i<=t;i++){
		cin>>s[i];
	}
	int x=s[1];
	int r=1;
	for(int i=1;i<t;i++){
		if(s[i]>x){
			r++;
		}
	}
	int c=(r-1)/n+1;
	int d=(r-1)%n;
	int r2;
	if(c%2==1){
		r2=d+1;
	}
	else{
		r2=n-d;
	}
	cout<<c<<" "<<r2<<endl;
	return 0;
}
