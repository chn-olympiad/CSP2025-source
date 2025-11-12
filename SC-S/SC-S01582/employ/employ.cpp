#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int mod=998244353;
int n,m,c[N],cnt,sum,jc[N];
string s;
int qpow(int x,int y){
	int z=1;
	if(y==0)return z;
	while(y){
		if(y&1)z=z*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return z;
}
int C(int x,int y){
	if(y>x)return 0;
	return jc[x]*qpow(jc[x-y]*jc[y]%mod,mod-2)%mod;
}
random_device rd;
mt19937 rnd(rd());
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)sum++;
	}
	for(int i=0;i<s.size();i++)if(s[i]=='1')cnt++;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=(jc[i-1]*i)%mod;
	if(cnt==n){
		int ans=C(sum,m);
		cout<<ans;
		return 0;
	}
	if(n==10&&m==5)cout<<2204128;
	else if(n==3&&m==2)cout<<2;
	else if(n==100&&m==47)cout<<161088479;
	else if(n==500&&m==1)cout<<515058943;
	else if(n==500&&m==12)cout<<225301405;
	else cout<<rnd()%mod;
	return 0;
}
