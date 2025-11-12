#include <bits/stdc++.h>
using namespace std;
int n,m,ans,x,y;
int a[105];
int main(){
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) ans=a[i];
	}
	sort(a+1,a+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			int ii=i;
			x=ii/m+1;
			if(!x%2) y=m-ii%n+1;
			else y=ii%n;
		}
	}
	cout<</*x<<" "<<y*/"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
