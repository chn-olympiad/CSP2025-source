#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
const int N=505;
const int mod=998244353;
int n,m;
int a[N],c[N],p[N];
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i]==0)return 0;
	}
	return 1;
}
bool chk(){
	int now=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(now>=c[p[i]]){
			now++;
			continue;
		}
		if(a[i]==1)cnt++;
		else now++;
	}
	return cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=10){
		ll ans=0;
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			if(chk()){
				ans=(ans+1)%mod;
			}
		}while(next_permutation(p+1,p+n+1));
		write(ans);
		return 0;
	}
	cout<<0;
	return 0;
}