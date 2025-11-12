#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],ma,v[5005],jl[5005];
long long ans,mod=998244353;
void f(int mu,int i){
	if(i==mu+1){
		long long ma=0,he=0;
		for(int j=1;j<i;j++){
			if(a[jl[j]]>ma)ma=a[jl[j]];
			he+=a[jl[j]];
		}
		if(ma*2<he){
			ans++;
//			cout<<ma<<"   "<<he<<"    ";
//			for(int j=1;j<i;j++)cout<<jl[j]<<" ";
//			cout<<'\n';
		}
		ans%=mod;
		return;
	}
	v[0]=1;
	for(int j=jl[i-1];j<=n;j++){
		if(v[j]==0){
			v[j]=1;
			jl[i]=j;
			f(mu,i+1);
			v[j]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)f(i,1);
	cout<<ans%mod;
	return 0;
}