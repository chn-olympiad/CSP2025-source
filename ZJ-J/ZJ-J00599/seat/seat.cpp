#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,a[N];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int aR=a[1],p=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==aR) {
			p=i;
		}
	}
	int lie=(p+n-1)/n,hang1=p%n,hang2=n-p%n+1;
	if(lie%2==1) {
		if(hang1==0){
			cout<<lie<<" "<<n;
		}else{
			cout<<lie<<" "<<hang1;
		}
	} else {
		cout<<lie<<" "<<hang2;
	}
	return 0;
}