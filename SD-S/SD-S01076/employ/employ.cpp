bool M1;
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<random>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>

#define ll long long
#define inf ((ll)1e18)
#define pc putchar
#define pb push_back
#define mid ((l+r)>>1)
#define lowbit(x) ((x)&(-(x)))
#define pir pair<int,int>
#define plr pair<ll,ll>
#define fi first
#define se second

using namespace std;

ll read(){
	ll w,f=1;char c;
	while((c=getchar())>'9'||c<'0')
		if(c=='-')f=-1;
	w=c-'0';
	while((c=getchar())>='0'&&c<='9')
		w=w*10+c-'0';
	return w*f;
}

signed NEV[102],NE;

void print(ll x){
	if(x<0)
		pc('-'),x=-x;
	if(x==0)
		pc('0');
	while(x)
		NEV[++NE]=x%10,x/=10;
	while(NE)
		pc(NEV[NE--]+'0');
}

const int N=5e2+5,mod=998244353;

int J[N],inv[N];
int qp(int x,int y){
	int ans=1;
	for(int i=1;i<=y;i<<=1){
		if(i&y)
			ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
	}return ans;
}
void load(int n){
	J[0]=inv[0]=1;
	for(int i=1;i<=n;i++)
		J[i]=1ll*J[i-1]*i%mod;
	inv[n]=qp(J[n],mod-2);
	for(int i=n-1;i>=1;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(n<m||m<0)
		return 0;
	return 1ll*J[n]*inv[m]%mod*inv[n-m]%mod;
}

char s[N];

int c[N],t[N];

int DU[(1<<18)+5][20];

void add(int &x,int y){
	x=x+y>=mod?x+y-mod:x+y;
}

int FU[N][N];
int suf[N];

bool M2;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cerr<<(&M1-&M2)/1024.0/1024.0<<endl;
	double st=clock();
	int n=read(),m=read();
	scanf("%s",s+1);
	bool flag=1;
	int cnt=0;
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]+(s[i]=='1');
		cnt+=s[i]=='0';
	}
	for(int i=1;i<=n;i++)
		flag&=s[i]=='1';
	for(int i=1;i<=n;i++)
		t[c[i]=read()]++;
	load(n);
	if(m==1){
		int ans=0,sum=0;
		FU[n+1][0]=1;
		for(int i=n;i>=0;i--){
			for(int j=0;j<=min(cnt,sum);j++){//zhiqiande si=0
				for(int k=0;k<=min(cnt-j,t[i]);k++){//xianzaide si=0
					add(FU[i][j+k],1ll*FU[i+1][j]*C(suf[i+1]-sum+j,t[i]-k)%mod*C(cnt-j,k)%mod*J[t[i]]%mod);
				}
			}sum+=t[i];
		}
		print((J[n]-FU[0][cnt]+mod)%mod),pc('\n');
	}else if(m==n){
		if(t[0]||!flag)
			print(0),pc('\n');
		else
			print(J[n]),pc('\n');
		return 0;
	}else if(n<=18){
		int all=(1<<n)-1;
		DU[0][0]=1;
		for(int k=1;k<=all;k++){
			int id=__builtin_popcount(k);
			if(s[id]=='0'){
				for(int i=1;i<=n;i++){
					if((k>>(i-1))&1){
						for(int l=0;l<id;l++)
							add(DU[k][l+1],DU[k^(1<<(i-1))][l]);
					}
				}
			}else{
				for(int i=1;i<=n;i++){
					if((k>>(i-1))&1){
						for(int l=0;l<id;l++){
							if(c[i]<=l)
								add(DU[k][l+1],DU[k^(1<<(i-1))][l]);
							else
								add(DU[k][l],DU[k^(1<<(i-1))][l]);
						}
					}
				}
			}
		}int ans=0;
		for(int i=m;i<=n;i++)
			add(ans,DU[all][n-i]);
		print(ans),pc('\n');
	}
	cerr<<(clock()-st)/1000.0<<endl;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
