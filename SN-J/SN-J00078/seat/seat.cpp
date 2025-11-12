#include<bits/stdc++.h>
using namespace std;
int all,ra;
int n,m;
int a[200],r;
int main(){
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	all=n*m;
	for(int i=0;i<all;i++) cin>>a[i];
	r=a[0];
	sort(a,a+all);
	for(int i=all-1;i>=0;i--){
		if(a[i]==r){
			ra=all-i;
			break;
    	}
	}
	freopen("seat.out","w",stdout);
	if(ra<=n){
		cout<<1<<" "<<ra;
	}
	else{
		cout<<ra/n+1<<" ";
		if((ra/n+1)%2!=0) cout<<ra%n;
		else cout<<m-ra%m+1;
	}
	return 0;
}
