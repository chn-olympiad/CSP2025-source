#include<bits/stdc++.h>
using namespace std;
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ax,c,r,ii;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ax=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==ax){
			ii=n*m+1-i;
			c=(ii-1)/n+1;
			if(c%2==0){
				r=(n+1)-ii+(c-1)*n;
			}
			else r=ii-(c-1)*n;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
}
