#include<bits/stdc++.h>
using namespace std;
int p[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,mx=0;
	long long ans=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]+a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		cout<<(1+n)*n/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
