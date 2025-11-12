#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int s;
int vis[5005];
int d[5005];
int num;
int ans;
bool cmp(int x,int y){
	return x>y;
}
void todo(int num){
	sort(d+1,d+num+1,cmp);
	int s=0;
	int flag=0;
	for(int i=1;i<=num;i++){
		if(!d[i]){
			flag=1;
		}
	}
	if(!flag){
		for(int i=2;i<=num;i++){
			s+=d[i];
		}
		if(s>d[1]){
			ans++;
		}
	}
}
void dg(int c,int deep){
	if(deep>num){
		todo(num);
		return ;
	}
	for(int i=c;i<=n;i++){
		if(!vis[i]){
			d[deep]=a[i];
			vis[i]=1;
			dg(deep+1,i+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=0;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[1]>=a[2]+a[3]){
			cout<<0;
			return 0;
		}
		cout<<1;
		return 0;
	}
	long long x=2;
	long long y=n*(n-1);
	for(int i=3;i<=n;i++){
		num=i;
		for(int j=1;j<=n;j++){
			dg(j,1);
		}
	}
	cout<<ans%mod;
	return 0;
}
