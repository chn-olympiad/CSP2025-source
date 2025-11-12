#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define mk make_pair
#define x first
#define y second
#define N 505
#define mod 998244353
using namespace std;
struct mint{
	int x;
	mint(ll y=0,bool fg=0){
		if(fg)x=(int)(y);
		else x=(int)((y%mod+mod)%mod);
	}
	friend mint ksm(mint a,ll b);
	const mint inv(){
		return ksm(*this,mod-2);
	}
};
mint operator +(const mint a,const mint b){
	int res=a.x+b.x;
	if(res>=mod)res-=mod;
	return mint(res,1);
}
mint operator -(const mint a,const mint b){
	int res=a.x-b.x;
	if(res<0)res+=mod;
	return mint(res,1);
}
mint operator *(const mint a,const mint b){
	return mint(1ll*a.x*b.x%mod,1);
}
mint operator +=(mint &a,const mint b){
	a=a+b;
	return a;
}
mint operator -=(mint &a,const mint b){
	a=a-b;
	return a;
}
mint operator *=(mint &a,const mint b){
	a=a*b;
	return a;
}
istream& operator >>(istream &in,mint &b){
	ll y;in>>y;
	b=mint(y);
	return in;
}
ostream& operator <<(ostream &out,mint b){
	return out<<b.x;
}
mint ksm(mint a,ll b){
	mint res=1;
	for(;b;b>>=1,a*=a)
		if(b&1)res*=a;
	return res;
}
int n,m;
int s[N];
int a[N];
mint f[2][N][N];
mint jie[N];
int tong[N],hou[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	jie[0]=1;
	for(int i=1;i<=n;++i)jie[i]=jie[i-1]*i;
	m=n-m;
	//最多不录用m人！！！！ 
	for(int i=1;i<=n;++i){
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++tong[a[i]];
	}
	for(int i=n;i>=0;--i){
		hou[i]=hou[i+1]+tong[i];
	}
	int sum=0;
	int now=0;
	for(int i=1;i-1<=m;++i){
		//>=i
		f[now][i][hou[i]]=1;
	}
	for(int i=n+1;i>=2;--i){
		memset(f[now^1],0,sizeof(f[now^1]));
		for(int j=1;j<=m+1;++j){
			for(int k=0;k<=n;++k){
				if(f[now][j][k].x==0)continue;
				if(s[i-1]==0){
					f[now^1][j-1][k+tong[j-1]]+=f[now][j][k];
					continue;
				}
				//>=i
				if(k)
					f[now^1][j][k-1]+=f[now][j][k]*k;
				//<i-1
				f[now^1][j-1][k+tong[j-1]]+=f[now][j][k];
				if(k+tong[j-1])
					f[now^1][j-1][k+tong[j-1]-1]-=f[now][j][k]*(k+tong[j-1]);
			}
		}
		now^=1;
	}
	mint ans=0;
	for(int i=tong[0];i<=n;++i){
		ans+=f[now][1][i-tong[0]]*jie[i];
	}
	cout<<ans<<'\n';
	return 0;
}
/*
20 5
11110011101110111110
0 2 0 1 0 5 8 9 1 2 1 5 0 4 1 0 4 5 9 20

2 0
11
0 1
3 0
111
0 1 2
1 2 0
2 1 0
1 0 2

Ren5Jie4Di4Ling5%
*/
