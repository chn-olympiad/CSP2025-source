#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],ac;
long long ans;
int maxwen(int s,int t){
	int maxa=-1e5;
	for(int i=s;i<=t;i++)if(a[i]>maxa)maxa=a[i];
	return maxa;
}
long long cheng(int xxx,int yyy){
	long long ccc=1;
	for(int i=xxx;i<=yyy;i++)ccc*=i;
	return ccc;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)ac=1;
	}
	if(ac==0){//部分分
		for(int i=3;i<=n;i++)ans+=(cheng(n-i+1,n)/cheng(2,i))%998244353;
		cout<<ans%998244353;
		return 0;
	}
	if(n<3){//部分分
		cout<<0;
		return 0;
	}if(n==3){
		if(a[0]+a[1]+a[2]>2*maxwen(0,2))cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)b[i]=b[i-1]+a[i];
	for(int i=0;i<n-2;i++){
		for(int j=i+2;j<n;j++){
			if(b[j]-b[i-1]>2*maxwen(i,j))ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
}
