#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=500+3,INF=0x3f3f3f3f3f3f3f3f,MOD=998244353;
inline ll read(){
	ll x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,c[MAXN];
ll ans;
string que;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>que;
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(c[i]==0||que[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
	}
	
	return 0;
}


