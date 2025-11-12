#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],sum[100005],cnt=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			sum[i]=max(a[j],max(b[j],c[j]));
		}
			cout<<sum<<endl;
	}
	/*
	for(int i=1;i<=t;i++){
		cout<<sum[i]<<endl;
	}
	*/
	return 0;
} 
