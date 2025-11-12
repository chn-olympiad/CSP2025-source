#include<bits/stdc++.h>
using namespace std;

const int p=998244353,N=805;
int f[1<<20][20];
int n,m,a[N],c[N];

void add(int &x,int y){
	x+=y;
	x%=p;
}

int popc(int x){
	int c=0;
	while(x){
		c++;
		x-=x&-x;
	}
	return c;
}

int gt(int x,int y){
	return (x>>y)&1;
}

namespace n18{
	void solve(){
		int ans=0;
		f[0][0]=1;//没用j个 
		for(int s=0;s<(1<<n);s++){//
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(gt(s,j))
						continue;
					int nw=popc(s);
					if(i>=c[j]||a[nw]==0)
						add(f[s|(1<<j)][i+1],f[s][i]);
					else 
						add(f[s|(1<<j)][i],f[s][i]);
				}
			}
		}
		for(int i=0;i<=n;i++){
			int j=n-i;
			if(j>=m){
				add(ans,f[(1<<n)-1][i]);
			}
		} 
		cout<<ans<<'\n';
	}
}

namespace nm{
	void solve(){
		int a0=0,c0=0; 
		for(int i=0;i<n;i++){
			if(a[i]==0)
				a0=1;
			if(c[i]==0)
				c0=1; 
		} 
		if(a0||c0)
			cout<<0<<'\n';
		else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=1ll*ans*i%p;
			}
			cout<<ans<<'\n';
		}		
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		a[i]=(c=='1');
	} 
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n<=18){
		n18::solve();
		return 0;
	}

	if(n==m){
		nm::solve();
		return 0;
	}
	cout<<0;

	return 0;
}

/*
这不熔池，
一个都不能选，找到这个的方案

如果在前面的c更小的被选了，那么更大的一定 
 

至少m个人啊 

c=0的

按照c从小到大，那么 

*/
