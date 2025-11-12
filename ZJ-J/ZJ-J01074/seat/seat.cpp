#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],r,wz;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*n+j];
		}
	}
	r=a[1];
	sort(a+1,a+1+n*m,greater<long long>());
	for(int i=1;i<=n*m;i++) if(a[i]==r){wz=i;break;}
	long long p=wz%(2*n),q=wz/n;
	if(wz%n!=0)q++;
	if(p==0)p=n;
	if(p>n){
		cout<<q<<' '<<2*n-p+1;
	}
	else{
		cout<<q<<' '<<p;
	}
	return 0;
}
