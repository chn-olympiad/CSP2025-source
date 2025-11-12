#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,rk,sc;
int a[105];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++) if(a[i]==sc) rk=i;
	r=rk/n+(rk%n>0);
	int c=rk%n;
	if(c==0){
		if(r%2==0) c=1;
		else c=m;
		cout<<r<<' '<<c;
		return 0;
	}
	if(r%2==1){
		cout<<r<<' '<<c;
	}else{
		cout<<r<<' '<<m-c+1;
	}
	return 0;
}
