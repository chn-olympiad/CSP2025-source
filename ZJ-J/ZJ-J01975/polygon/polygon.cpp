#include<bits/stdc++.h>
using namespace std;
long long n,m,c,k,r,t=0,a[1000010],s[1000010],x,y;
const int mod=998244353;

//void dfs(int )
int cc(int m,int k){//m zhong qu k
	k=min(k,m-k);
	int ss=1,t=1;
	for(int i=1;i<=k;i++){
		t=i*(t%mod);
		ss=(ss%mod)*(m+1-i)%mod;
	}return (ss/t)%mod;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;

	for(int i=1;i<=n;i++){	cin>>a[i];	}
	sort(a+1,a+1+n);s[0]=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	if(n<=3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}

	
	if(a[n]==1){
		int s=1;
		for(int i=1;i<=n;i++){
			s%=mod;
			s=s*2;
			
		}cout<<(s-cc(n,2)-n-1)%mod;return 0;
	}
	else 
	{
		int s=1;
		for(int i=1;i<=n;i++){
			s%=mod;
			s=s*2;
			
		}cout<<(s-cc(n,2)-n-1)%mod;return 0;
	}
	return 0;
}
//4 2 2 1 0 3
