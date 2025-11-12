#include<bits/stdc++.h>
using namespace std;
long long n,m,f,a[5001],x,s;
void dd(int awsq,int y){
	s++;
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	if(f==0){
		for(int i=3;i<=n;i++){
			m=n;
			x=1;
			for(int j=1;j<=i;j++){
				x=x*m/j%998244353;
				m--;
				s=(s+x)%998244353;
			}
		}
	}
	else{
		for(int i=3;i<=n;i++)
		    for(int j=1;j<=n-i+1;j++)
		        dd(i,j);
	}
	cout<<s;
	return 0;
}
