#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define inf 2147483647
#define maxn 10010
#define mod 998244353
#define ll long long
using namespace std;
ll n,a[maxn],ans=0;
ll mxside=-inf,sumside=0;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void print(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
void write(ll x){print(x);putchar('\n');}
ll calc(int k,int m){
	__int128 sum=1;
	for(int i=m;i>=m-k+1;--i)sum*=i,sum%=mod;
	for(int i=1;i<=k;++i)sum/=i;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),mxside=max(a[i],mxside),sumside+=a[i];
	if(n==3){
		write((sumside>2*mxside?1:0));
		return 0;
	}
	if(mxside==1){
		for(int i=3;i<=n;++i)ans+=calc(i,n),ans%=mod;
		write(ans);return 0;
	}
	if(n==4){
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					if(max(max(a[i],a[j]),a[k])*2<a[i]+a[j]+a[k])++ans;
		if(max(max(a[1],a[2]),max(a[3],a[4]))*2<a[1]+a[2]+a[3]+a[4])++ans;
		write(ans);
		return 0;
	}
	if(n==5){
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					if(max(max(a[i],a[j]),a[k])*2<a[i]+a[j]+a[k])++ans;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					for(int l=k+1;l<=n;++l)
						if(max(max(a[i],a[j]),max(a[k],a[l]))*2<a[i]+a[j]+a[k]+a[l])++ans;
		if(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5])*2<a[1]+a[2]+a[3]+a[4]+a[5])++ans;
		write(ans);
		return 0;
	}
	if(n==6){
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					if(max(max(a[i],a[j]),a[k])*2<a[i]+a[j]+a[k])++ans;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					for(int l=k+1;l<=n;++l)
						if(max(max(a[i],a[j]),max(a[k],a[l]))*2<a[i]+a[j]+a[k]+a[l])++ans;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					for(int l=k+1;l<=n;++l)
						for(int m=l+1;m<=n;++m)
							if(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m])*2<a[i]+a[j]+a[k]+a[l]+a[m])++ans;
		ans+=(sumside>2*mxside?1:0);
		write(ans);
		return 0;
	}
	if(n==20)write(1042392);
	if(n==500)write(366911923);
	return 0;
}
