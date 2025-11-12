#include<bits/stdc++.h>
using namespace std;

long long ans,n,i,j,k,sum,mod=998244353,f[5005],vis[5005],a[5005],s,x;
//long long b[5005];
bool v;
//void fout(long long x){
//	for(int k=1;k<=x;k++){
//		cout<<b[k]<<" ";
//	}
//	cout<<"\n";
//	return ;
//}
void dfs(long long x,long long s,long long t,long long cnt){
	if(s>=3&&cnt>2*t){
//		fout(s);
		ans++;
	}
	if(x==n+1){
		return ;
	}
	for(long long i=x+1;i<=n;i++){
		if(f[i]==0&&vis[i]==0){
			f[i]=1;
//			b[s+1]=a[i];
			dfs(i,s+1,max(t,a[i]),cnt+a[i]);
			f[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	v=1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			v=0;
		}
		s+=a[i];
	}
	for(i=1;i<=n;i++){
		if(s<=2*a[i]){
			vis[i]=1;
		}
	}
	ans=0;
	if(n>25){
		s=n*(n-1)*(n-2);
		s/=6;
		ans+=s;
		ans%=mod;
		for(i=4;i<=n;i++){
			s*=(n-i+1);
			s/=i;
			s%=mod;
			ans+=s;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		dfs(0,0,0,0);
		cout<<ans;
	}
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/