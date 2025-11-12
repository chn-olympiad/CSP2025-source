#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cou=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		int c=a[i],d;
		for(int j=i+1;j<=n;j++){
			c+=a[j];
			d=j;
		}
		if(c>2*a[d]) cou++;
	}
	cout<<cou%998244353;
	return 0;
}
