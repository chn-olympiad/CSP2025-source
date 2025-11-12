#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010],n,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(int u=1;u<=t;u++){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--)sum=sum+a[i];
	}
	cout<<sum;
	return 0;
}
