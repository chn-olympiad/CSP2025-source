#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long n,a[5005],t=INT_MIN,b,c=1,d=1,e=1,s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		c=(c*i)%M;
		cin>>a[i];
		t=max(t,a[i]);
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>t*2) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1) b=1;
	}
	if(b==0){
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			d=(d*j)%M;
		}
		for(int j=1;j<=n-i;j++){
			e=(e*j)%M;
		}
		s=(s%M)+(c/(d*e))%M;
		d=1;
		e=1;
		}
	}
	cout<<s;
	return 0;        
}