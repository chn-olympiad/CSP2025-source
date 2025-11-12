#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n;
int a[100001];
int qz[100001];
long long ans;
int pl(int nn){
	int as=1;
	for(int i=0;i<nn;i++){
		as*=2;
		as%=md;
	}
	as--;
	return as;
}
void f(int nw,int sum,int ms,int l){
	if(sum>a[ms]){
		ans+=pl(ms-nw+1);
		ans%=md;
		return ;
	}
	if(nw==ms){
		return ;
	}
	for(int i=nw;i<ms;i++){
		if(sum+qz[ms-1]-qz[nw-1]<=a[ms]){
			break;
		}
		f(i+1,sum+a[i],ms,l+1);
		if(sum+a[i]>a[ms]){
			return ;
		}
	}
}
bool fl=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			fl=0;
		}
	}
	if(fl){
		for(int i=3;i<=n;i++){
			ans+=pl(i-1);
			ans=ans-i+1;
			ans%=md;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		f(1,0,i,0);
	}
	cout<<ans;
} 
