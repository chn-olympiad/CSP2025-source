#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,b,a) for(int i=(b);i>=(a);i--)
#define mem(a,b) memset(a,b,sizeof(a));

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int mod=998244353;
const int N=5005;
ll n,a[N],ans,c[N][N],maxn,sumn;

void init(int n){
	rep(i,1,n){
		rep(j,1,n){
			if(i==j) c[i][j]==1;
			if(j==1) c[i][j]=i;
			else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sumn+=a[i];
	}
	if(n==3){
		if(sumn>2*maxn){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(sumn==n){
		init(n);
		rep(i,3,n){
			ans=(ans+c[n][i])%mod;
		}
		cout<<ans;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

