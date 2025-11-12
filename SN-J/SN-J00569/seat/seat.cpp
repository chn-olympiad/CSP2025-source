#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
long long n,m,s[15],a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1; i<=l; i++) cin>>a[i];
	int g=a[1];
	sort(a+1,a+l+1,cmp);
	int gra;
	for(int i=1; i<=l; i++){
		if(g==a[i]) gra=i;
	}
	int ll=gra/n;
	int r=gra%n;
	if(r!=0) ll++;
	else r=n;
	int rr;
	if(ll%2==0) rr=n-r+1;
	else rr=r;
	
	cout<<ll<<" "<<rr;
	return 0;
}
