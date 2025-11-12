#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ma=-1,sum=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		ma=max(ma,a[i]);
	}
	int i=3;
	if(n==3&&sum>2*ma)cout<<1;
	else if(n==3&&sum<=2*ma)cout<<0;
	else if(ma==1)cout<<n*(n-1)*(n-2)/6;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
