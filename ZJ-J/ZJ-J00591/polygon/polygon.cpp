#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n,fl,x,ans,a[5005],C[5005];
bool pd(int sl,int zd,int he){
	if(sl<2)return 0;
	if(he<=zd)return 0;
	return 1;
}
void sc(int t,int sl,int mb,int zd,int h){
	if(t==mb){
		if(pd(sl,zd,h))ans=(ans+1)%Mod;
		return ;
	}
	sc(t+1,sl+1,mb,zd,h+a[t]);
	sc(t+1,sl,mb,zd,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w".stdout);
	cin>>n;fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
	}
	if(fl==1){
		C[1]=n;
		for(int i=2;i<=n;i++)
			C[i]=C[i-1]*(n-i+1)/i;
		for(int i=3;i<=n;i++){
			ans=(ans+C[i])%Mod;
		}
		cout<<ans;return 0;
	}
	else{
		sort(a+1,a+1+n);
		for(int i=3;i<=n;i++)
		sc(1,1,i,a[i],0);
		cout<<ans;
	}
	return 0;
}

