#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n;
int a[N],vis[N],b[N];
unsigned long long ans;
int zh(int a,int b){
	unsigned long long s1=1,s2=1,s3=1;
	if(b-a>a){
		for(int i=2;i<=a;i++)s1*=i;
		for(int i=b-a+1;i<=b;i++)s2*=i;
//		for(int i=2;i<=(b-a);i++)s3*=i;
		int res=s2/s1/s3;
		return res%mod;
	}
	if(b-a<=a){
//		for(int i=2;i<=a;i++)s1*=i;
		for(int i=a+1;i<=b;i++)s2*=i;
		for(int i=2;i<=(b-a);i++)s3*=i;
		int res=s2/s1/s3;
		return res%mod;
	}
}
void dfs(int x,int sx,int mx,int sum){
	if(x>n){
		if(sx>=3&&mx*2<sum){
			ans++;
			ans%=mod;
			return ;
		}
		else return ;
	}
	dfs(x+1,sx,mx,sum);
	b[x]=a[x];
	dfs(x+1,sx+1,max(mx,a[x]),sum+a[x]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1){
		for(int i=3;i<=n;i++){
			ans+=zh(i,n);
			ans%=mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	ans=0;
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}

